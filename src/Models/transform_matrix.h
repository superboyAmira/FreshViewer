#ifndef SRC_MODELS_TRANSFORM_MATRIX_H_
#define SRC_MODELS_TRANSFORM_MATRIX_H_

#include "Matrix/matrix.h"
#include "point3d.h"

namespace s21
{
    class TransformMatrix {
        public:
            Point3D* TransformPoint(Point3D points) {
                
            };
        private:
            Matrix matrix_;

    };

    class TransformMatrixBuilder {
        public:
            static TransformMatrix CreateRotationMatrix(double x, double y, double z) {};
            static TransformMatrix CreateMoveMatrix(double x, double y, double z) {};
            static TransformMatrix CreateScaleMatrix(double x, double y, double z) {};
        private:
            TransformMatrix matrix_;
    };
} // namespace s21


#endif  // SRC_MODELS_TRANSFORM_MATRIX_H_