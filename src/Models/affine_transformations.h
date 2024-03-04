#ifndef SRC_MODELS_AFFINE_TRANSFORMATIONS_H_
#define SRC_MODELS_AFFINE_TRANSFORMATIONS_H_

#include "scene.h"

/*!
    \details В данном классе используется поведенческий паттерн Стратегия.
    BaseTransformation выступает в роли абстрактного класса (интерфейса)
    для производных классов MoveTransformation, RotateTransformation, ScaleTransformation.
*/

namespace s21
{
    /*!
        \brief Абстрактный класс стратегий для афинных преобразований.
    */
    class BaseTransormation {
        public:
            virtual ~BaseTransormation() = default;
            virtual void TransformSceneX(double x, Scene& scene) = 0;
            virtual void TransformSceneY(double y, Scene& scene) = 0;
            virtual void TransformSceneZ(double z, Scene& scene) = 0;
    };

    /*!
        \brief Дочерний класс релизующий стратегию перемещения 3Д модели.
    */
    class MoveTransformation : public BaseTransormation {
        public:
            MoveTransformation() = default;

            ~MoveTransformation() noexcept = default; 

            /*!
                \brief Перемещение 3Д модели относительно 3-х осей согласно коэффицентам.
                \param x коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().X += x;
                }
            };

            /*!
                \brief Перемещение 3Д модели относительно 3-х осей согласно коэффицентам.
                \param y коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneY(double y, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().Y += y;
                }
            };

            /*!
                \brief Перемещение 3Д модели относительно 3-х осей согласно коэффицентам.
                \param z коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneZ(double z, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().Z += z;
                }
            };
    };

    /*!
        \brief Дочерний класс релизующий стратегию поворта 3Д модели.
    */
    class RotateTransformation : public BaseTransormation {
        public:
            RotateTransformation() = default;

            ~RotateTransformation() noexcept = default; 
            
            /*!
                \brief Поворот 3Д модели относительно 3-х осей согласно коэффицентам.
                \param x коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_y = it.base()->GetPosition().Y;
                    double temp_z = it.base()->GetPosition().Z;
                    it.base()->GetPosition().Y = temp_y * cos(x) + sin(x) * temp_z;
                    it.base()->GetPosition().Z = (-1 * temp_y) * sin(x) + cos(x) * temp_z;
                }
            };

            /*!
                \brief Поворот 3Д модели относительно 3-х осей согласно коэффицентам.
                \param y коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneY(double y, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_x = it.base()->GetPosition().X;
                    double temp_z = it.base()->GetPosition().Z;
                    it.base()->GetPosition().X = temp_x * cos(y) + sin(y) * temp_z;
                    it.base()->GetPosition().Z = (-1 * temp_x) * sin(y) + cos(y) * temp_z;
                }
            };

            /*!
                \brief Поворот 3Д модели относительно 3-х осей согласно коэффицентам.
                \param z коэффицент поворота.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneZ(double z, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    double temp_x = it.base()->GetPosition().X;
                    double temp_y = it.base()->GetPosition().Y;
                    it.base()->GetPosition().X = temp_x * cos(z) - temp_y * sin(z);
                    it.base()->GetPosition().Y = (-1 * temp_x) * sin(z) + temp_y * cos(z);
                }
            };
    };

    /*!
        \brief Дочерний класс релизующий стратегию изменения масштаба 3Д модели.
    */
    class ScaleTransformation : public BaseTransormation {
        public:
            ScaleTransformation() = default;
            
            ~ScaleTransformation() noexcept = default; 

            /*!
                \brief Изменеие масштаба 3Д модели.
                \param x коэффицент масштабирования.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneX(double x, Scene& scene) override {
                for (auto it = scene.GetFigures().at(0).GetVertices().begin(); it !=  scene.GetFigures().at(0).GetVertices().end(); ++it) {
                    it.base()->GetPosition().X *= x;
                    it.base()->GetPosition().Y *= x;
                    it.base()->GetPosition().Z *= x;
                }
            };
            
            /*!
                \brief Изменеие масштаба 3Д модели.
                \param y коэффицент масштабирования.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneY(double y, Scene& scene) override {
                TransformSceneX(y, scene);
            };
            
            /*!
                \brief Изменеие масштаба 3Д модели.
                \param z коэффицент масштабирования.
                \param scene ссылка на общий массив данных вершин.
            */
            void TransformSceneZ(double z, Scene& scene) override {
                TransformSceneX(z, scene);
            };
    };
} // namespace s21


#endif  // SRC_MODELS_AFFINE_TRANSFORMATIONS_H_
