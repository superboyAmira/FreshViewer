#ifndef SRC_MODELS_FILE_READER_H_
#define SRC_MODELS_FILE_READER_H_

#include <fstream>
#include <sstream>
#include <string>

#include "scene.h"

namespace s21 {
    class BaseFileReader {
        public:
            virtual ~BaseFileReader() noexcept = default;
            virtual Scene* ReadScene(std::string path) = 0;
    };

    class Reader : BaseFileReader {
        public:
            Reader() = default;
            ~Reader() noexcept override = default;

            Scene* ReadScene(std::string path) override {
                file_stream_.open(path);
                if (!file_stream_.is_open() || file_stream_.peek() == EOF) {
                    throw std::invalid_argument("FILE_READER/Bad file path");
                }
                SaveData();
                return &scene_;
            };

        private:
            std::ifstream file_stream_;
            Scene scene_;

            void SaveData() noexcept {
                scene_ = Scene();
                file_stream_.seekg(0);
                Point3D xyz;
                Vertex vertex;
                Figure* figure = new Figure();

                std::string line = std::string();
                size_t index = 0;
                
                while (getline(file_stream_, line)) {
                    if (line[0] == 'v' && line[1] == ' ') {
                        sscanf(line.c_str(), "%*s %lf %lf %lf", &xyz.X, &xyz.Y, &xyz.Z);
                        xyz.index = index++;
                        vertex.SetPosition(xyz);
                        figure->AddVertex(vertex);
                    } else if (line[0] == 'f' && line[1] == ' ') {
                        SaveDataPolygon(line.substr(2), figure);
                    }
                }
                scene_.AddFigure(figure);
                // delete figure;
                file_stream_.close();
            };

            void SaveDataPolygon(std::string f_line, Figure* figure) noexcept {
                std::istringstream iss(f_line);
                std::string token;
                std::vector<Vertex>& vertices = figure->GetVertices();
                Edge tmp_edge;
                int first_num = 0, current_num = 0;

                iss >> token;
                auto slash_pos = token.find('/');
                if (slash_pos != std::string::npos) {
                    first_num = std::stoi(token.substr(0, slash_pos)) - 1;
                } else {
                    first_num = std::stoi(token) - 1;
                }
                tmp_edge.SetBegin(&vertices.at(first_num));

                while (iss >> token) {
                    slash_pos = token.find('/');
                    if (slash_pos != std::string::npos) {
                        current_num = std::stoi(token.substr(0, slash_pos)) - 1;
                    } else {
                        current_num = std::stoi(token) - 1;
                    }
                    tmp_edge.SetEnd(&vertices.at(current_num));
                    figure->AddEdge(tmp_edge);
                    tmp_edge.clear();
                    tmp_edge.SetBegin(&vertices.at(current_num));
                }
                tmp_edge.SetEnd(&vertices.at(first_num));
                figure->AddEdge(tmp_edge);
            };
    };

} // namespace s21

#endif  // SRC_MODELS_FILE_READER_H_