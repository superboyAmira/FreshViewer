#ifndef SRC_MODELS_FIGURE_H_
#define SRC_MODELS_FIGURE_H_

#include <vector>

#include "Matrix/matrix.h"
#include "vertex.h"
#include "edge.h"

namespace s21
{
    class SceneObject {
        virtual void Transform(Matrix matrix) = 0;
    };
    
    class Figure : SceneObject {
        public:
            Figure() = default;
            ~Figure() noexcept = default;

            void AddEdge(Edge edge) { edges_.push_back(edge); };
            void AddVertex(Vertex vertex) { vertices_.push_back(vertex); };
            std::vector<Vertex>& GetVertices() noexcept { return vertices_; };
            std::vector<Edge>& GetEdges() noexcept { return edges_; };

            void Transform(Matrix matrix) override {};
        private:
            std::vector<Vertex> vertices_;
            std::vector<Edge> edges_;
    };
    
} // namespace s21


#endif  // SRC_MODELS_FIGURE_H_