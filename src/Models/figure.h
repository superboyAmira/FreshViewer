#ifndef SRC_MODELS_FIGURE_H_
#define SRC_MODELS_FIGURE_H_

#include <vector>

#include "Matrix/matrix.h"
#include "vertex.h"
#include "edge.h"

namespace s21
{
    class SceneObject {
        virtual void Transform(Matrix matrix) {};
    };
    
    class Figure : SceneObject {
        public:
            std::vector<Vertex>* GetVertices() const noexcept { return &vertices_; };
            std::vector<Edge>* GetEdges() const noexcept { return &edges_; };

            void Transform(Matrix matrix) override {};
        private:
            std::vector<Vertex> vertices_;
            std::vector<Edge> edges_;
    };
    
} // namespace s21


#endif  // SRC_MODELS_FIGURE_H_