#ifndef SRC_MODELS_FILE_READER_H_
#define SRC_MODELS_FILE_READER_H_

#include <fstream>
#include <vector>

#include "scene.h"

namespace s21 {
    class BaseFileReader {
        public:
            virtual ~BaseFileReader() = default;
            virtual Scene* ReadScene(std::string path) = 0;
    };

    class Reader : BaseFileReader {
        public:
            Reader() {};
            ~Reader() noexcept {};
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
                std::string line;
                size_t p = 1, i = 1;
                double first = 0.0, second = 0.0, third = 0.0;
                while (getline(file_stream_, line)) {
                    if (line[0] == 'v' && line[1] == ' ') {
                        sscanf(line.c_str(), "%*s %lf %lf %lf", &first, &second, &third);
                        scene_.AddVertices(first);
                        scene_.AddVertices(second);
                        scene_.AddVertices(third);
                        i++;
                    } else if (line[0] == 'f' && line[1] == ' ') {
                        // Передача строки с отделением первых двух символов ("f ")
                        SaveDataPolygon(line.substr(2));
                        p++;
                    }
                }
                file_stream_.close();
            };

            void SaveDataPolygon(std::string f_line) noexcept {
                 // Разбиваем строку на токены, используя пробельные символы в качестве
                // разделителей
                std::istringstream iss(f_line);
                std::string token;
                int first_num = 0, current_num = 0;

                // Обработка первого числа линии
                iss >> token;
                auto slash_pos = token.find('/');
                if (slash_pos != std::string::npos) {
                    first_num = std::stoi(token.substr(0, slash_pos)) - 1;
                } else {
                    first_num = std::stoi(token) - 1;
                }
                scene_.AddLines(current_num);

                while (iss >> token) {
                    // Ищем символ "/"
                    slash_pos = token.find('/');
                    if (slash_pos != std::string::npos) {
                        // Если символ "/" найден, берем только то, что до него
                        current_num = std::stoi(token.substr(0, slash_pos)) - 1;
                    } else {
                        // Если символ "/" не найден, берем весь токен
                        current_num = std::stoi(token) - 1;
                    }

                    scene_.AddLines(current_num);
                    scene_.AddLines(current_num);
                }
                // Для замыкания фигуры
                scene_.AddLines(first_num);
            };

    };

} // namespace s21

#endif  // SRC_MODELS_FILE_READER_H_