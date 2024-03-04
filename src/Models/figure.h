#ifndef SRC_MODELS_FIGURE_H_
#define SRC_MODELS_FIGURE_H_

#include <vector>

#include "edge.h"
#include "vertex.h"

namespace s21 {
/*!
    \brief Абстрактный класс объекта Scene, будет использоваться в будующем.
*/
class SceneObject {
 public:
  ~SceneObject() noexcept = default;
};

/*!
    \brief Класс хранящий конкретные массивы обработанных вершин и индексов
   файла.
*/
class Figure : SceneObject {
 public:
  Figure() = default;
  ~Figure() noexcept = default;

  /*!
      \brief Сеттер линий в приватное поле типа std::vector<Edges>.
      \param edge линия для помещения в вектор.
  */
  void AddEdge(Edge edge) { edges_.push_back(edge); };

  /*!
      \brief Сеттер вершин в приватное поле типа std::vector<Vertex>.
      \param vertex вершина для помещения в вектор.
  */
  void AddVertex(Vertex vertex) { vertices_.push_back(vertex); };

  /*!
      \brief Геттер вершин из приватного поле типа std::vector<Vertex>.
      \return std::vector<Vertex>&
  */
  std::vector<Vertex>& GetVertices() noexcept { return vertices_; };

  /*!
      \brief Геттер линий из приватного поле типа std::vector<Edge>.
      \return std::vector<Edge>&
  */
  std::vector<Edge>& GetEdges() noexcept { return edges_; };

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};

}  // namespace s21

#endif  // SRC_MODELS_FIGURE_H_
