#ifndef SRC_MODELS_SCENE_H_
#define SRC_MODELS_SCENE_H_

#include <cmath>
#include "figure.h"

namespace s21 {

    /*!
        \brief Класс который хранит информацию о векторе фигур в обработанном файле.
    */
    class Scene {
        public:
            ~Scene() noexcept = default;

            /*!
                \brief Сеттер фигур в приватное поле типа std::vector<Figures>.
                \param figure фигура для помещения в вектор.
            */
            void AddFigure(Figure figure) noexcept {
                figures_.resize(1);
                figures_.reserve(1);
                figures_.at(0) = std::move(figure);
            };

            /*!
                \brief Геттер фигур из приватного поле типа std::vector<Figures>.
                \return std::vector<Figure>&
            */
            std::vector<Figure>& GetFigures() noexcept { return figures_; };

        private:
            std::vector<Figure> figures_;

    };
} // namespace s21


#endif  // SRC_MODELS_SCENE_H_
