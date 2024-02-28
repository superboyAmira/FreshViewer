#ifndef SRC_MODELS_SCENE_H_
#define SRC_MODELS_SCENE_H_

#include <vector>

#include "Matrix/matrix.h"
#include "figure.h"

namespace s21 {
    class Scene {
        public:
            void AddFigure(Figure* figure) noexcept { 
                figures_.push_back(*figure);
            };
            std::vector<Figure>& GetFigures() noexcept { return figures_; };
            void Transform(Matrix& matrix) {};

        private:
            std::vector<Figure> figures_;

    };
} // namespace s21


#endif  // SRC_MODELS_SCENE_H_