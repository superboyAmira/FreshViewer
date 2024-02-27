#ifndef SRC_MODELS_TRANSFORM_MATRIX_H_
#define SRC_MODELS_TRANSFORM_MATRIX_H_

#include "Matrix/matrix.h"
#include "point3d.h"

namespace s21
{
    class TransformMatrix {
        public:
            Point3D* TransformPoint(Point3D points) {};
        private:
            Matrix matrix_;

    };
} // namespace s21


#endif  // SRC_MODELS_TRANSFORM_MATRIX_H_