#ifndef SRC_MODELS_VERTEX_H_
#define SRC_MODELS_VERTEX_H_

#include "point3d.h"

namespace s21 {
    class Vertex {
        public:

            void SetPosition(Point3D xyz) { position_ = xyz; };
            Point3D& GetPosition() noexcept { return position_; };

            void Transform() {};
        private:
            Point3D position_;
    };
}

#endif  // SRC_MODELS_VERTEX_H_