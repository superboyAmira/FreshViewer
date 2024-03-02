#ifndef SRC_MODELS_AFFINE_TRANSFORMATIONS_H_
#define SRC_MODELS_AFFINE_TRANSFORMATIONS_H_

#include "scene.h"

/*
В данном классе используется поведенческий паттерн Шаблонный метод.
BaseTransformation выступает в роли абстрактного класса (интерфейса)
для производных классов MoveTransformation, RotateTransformation, ScaleTransformation.
*/

namespace s21
{
    class BaseTransormation {
        public:
            virtual ~BaseTransormation() = default;
            virtual void TransformSceneX(double x, Scene& scene) = 0;
            virtual void TransformSceneY(double y, Scene& scene) = 0;
            virtual void TransformSceneZ(double z, Scene& scene) = 0;
            // virtual void TransformSceneScale(double angle, Scene& scene);
    };

    class MoveTransformation : public BaseTransormation {
        public:
            MoveTransformation() = default;
            ~MoveTransformation() noexcept = default; 

            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().X += x;
                }
            };
            void TransformSceneY(double y, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().Y += y;
                }
            };
            void TransformSceneZ(double z, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().Z += z;
                }
            };
    };

    class RotateTransformation : public BaseTransormation {
        public:
            RotateTransformation() = default;
            ~RotateTransformation() noexcept = default; 
            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_y = it.base()->GetPosition().Y;
                    double temp_z = it.base()->GetPosition().Z;
                    it.base()->GetPosition().Y = temp_y * cos(x) + sin(x) * temp_z;
                    it.base()->GetPosition().Z = (-1 * temp_y) * sin(x) + cos(x) * temp_z;
                }
            };
            void TransformSceneY(double y, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_x = it.base()->GetPosition().X;
                    double temp_z = it.base()->GetPosition().Z;
                    it.base()->GetPosition().X = temp_x * cos(y) + sin(y) * temp_z;
                    it.base()->GetPosition().Z = (-1 * temp_x) * sin(y) + cos(y) * temp_z;
                }
            };
            void TransformSceneZ(double z, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_x = it.base()->GetPosition().X;
                    double temp_y = it.base()->GetPosition().Y;
                    it.base()->GetPosition().X = temp_x * cos(z) - temp_y * sin(z);
                    it.base()->GetPosition().Y = (-1 * temp_x) * sin(z) + temp_y * cos(z);
                }
            };
    };

    class ScaleTransformation : public BaseTransormation {
        public:
            ScaleTransformation() = default;
            ~ScaleTransformation() noexcept = default; 
            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().X *= x;
                    it.base()->GetPosition().Y *= x;
                    it.base()->GetPosition().Z *= x;
                }
            };
            void TransformSceneY(double y, Scene& scene) override {
                TransformSceneX(y, scene);
            };
            void TransformSceneZ(double z, Scene& scene) override {
                TransformSceneX(z, scene);
            };
    };
} // namespace s21


#endif  // SRC_MODELS_AFFINE_TRANSFORMATIONS_H_
