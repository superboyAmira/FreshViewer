#ifndef SRC_MODELS_VERTEX_H_
#define SRC_MODELS_VERTEX_H_

#include "point3d.h"

namespace s21 {

/*!
    \brief Класс хранящий конкретный экземпляр вершины с структурой (Point3D) ее
   координат.
*/
class Vertex {
 public:
  Vertex() = default;

  ~Vertex() = default;

  /*!
      \brief Сеттер координат вершины в приватное поле типа Point3D.
      \param xyz
  */
  void SetPosition(Point3D xyz) { position_ = xyz; };

  /*!
      \brief Геттер координат вершины.
      \return Point3D&
  */
  Point3D& GetPosition() noexcept { return position_; };

 private:
  Point3D position_;
};
}  // namespace s21

#endif  // SRC_MODELS_VERTEX_H_