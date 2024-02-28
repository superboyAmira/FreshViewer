#ifndef SRC_MODELS_FILE_READER_H_
#define SRC_MODELS_FILE_READER_H_

#include <fstream>
#include <sstream>
#include <string>

#include "scene.h"

namespace s21 {
    class BaseFileReader {
        public:
            virtual ~BaseFileReader() = default;
            virtual Scene* ReadScene(std::string path) = 0;
    };

    class Reader : BaseFileReader {
        public:
            Reader() = default;
            ~Reader() noexcept = default;

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
                Point3D* xyz = new Point3D();
                Vertex* vertex = new Vertex();
                Figure* figure = new Figure();

                std::string line;
                // size_t p = 1, i = 1;
                
                while (getline(file_stream_, line)) {
                    if (line[0] == 'v' && line[1] == ' ') {
                        sscanf(line.c_str(), "%*s %lf %lf %lf", &xyz->X, &xyz->Y, &xyz->Z);
                        vertex->SetPosition(*xyz);
                        figure->AddVertex(*vertex);
                        // i++;
                    } else if (line[0] == 'f' && line[1] == ' ') {
                        SaveDataPolygon(line.substr(2), figure);
                        // p++;
                    }
                }
                scene_.AddFigure(figure);
                file_stream_.close();
            };

            void SaveDataPolygon(std::string f_line, Figure* figure) noexcept {
                std::istringstream iss(f_line);
                std::string token;
                int first_num = 0, current_num = 0;
                Edge* tmp_edge = new Edge();
                std::vector<Vertex>* vertices = figure->GetVertices();

                iss >> token;
                auto slash_pos = token.find('/');
                if (slash_pos != std::string::npos) {
                    first_num = std::stoi(token.substr(0, slash_pos)) - 1;
                } else {
                    first_num = std::stoi(token) - 1;
                }
                Vertex first_vertex = vertices->at(first_num); 
                tmp_edge->SetBegin(&first_vertex);

                while (iss >> token) {
                    slash_pos = token.find('/');
                    if (slash_pos != std::string::npos) {
                        current_num = std::stoi(token.substr(0, slash_pos)) - 1;
                    } else {
                        current_num = std::stoi(token) - 1;
                    }
                    Vertex curr_vertex = vertices->at(current_num);
                    tmp_edge->SetEnd(&curr_vertex);
                    figure->AddEdge(*tmp_edge);
                    tmp_edge->SetBegin(&curr_vertex);
                }
                tmp_edge->SetEnd(&first_vertex);
                figure->AddEdge(*tmp_edge);
            };

    };

} // namespace s21

#endif  // SRC_MODELS_FILE_READER_H_