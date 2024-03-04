#ifndef SRC_MODELS_POINT3D_H_
#define SRC_MODELS_POINT3D_H_

#include <cstddef>

namespace s21 {
/*!
    \brief Структура хранящяя координаты и порядковый индекс конкретного
   экземляра класса Vertex. \param X double \param Y double \param Z double
    \param index std::size_t
*/
typedef struct Point3D {
  double X = 0.0;
  double Y = 0.0;
  double Z = 0.0;
  size_t index;
} Point3D;

}  // namespace s21

#endif  // SRC_MODELS_POINT3D_H_
