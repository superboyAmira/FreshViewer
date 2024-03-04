#ifndef SRC_MODELS_EDGE_H_
#define SRC_MODELS_EDGE_H_

#include "vertex.h"

namespace s21 {

    /*!
        \brief Класс хранящий конкретный экземпляр линии.
        \details size_t begin_ - индекс начала линии, size_t end_ - индекс конца линии.
    */
    class Edge {
        public:
            ~Edge() noexcept = default;

            /*!
                \brief Очистка данных класса.
            */
            void clear() noexcept {
                begin_ = 0;
                end_ = 0;
            };

            /*!
                \brief Сеттер начального индекса вершин в приватное поле типа size_t.
                \param begin индекс начальной вершины.
            */
            void SetBegin(size_t begin) noexcept { begin_ = begin; };

            /*!
                \brief Сеттер конченого индекса вершин в приватное поле типа size_t.
                \param end индекс конечной вершины.
            */
            void SetEnd(size_t end) noexcept { end_ = end; };

            /*!
                \brief Геттер начального индекса вершин.
                \return size_t
            */
            size_t GetBegin() const noexcept { return begin_; };

            /*!
                \brief Геттер конченого индекса вершин.
                \return size_t
            */
            size_t GetEnd() const noexcept { return end_; };
            
        private:
            size_t begin_;
            size_t end_;
    };
}

#endif  //  SRC_MODELS_EDGE_H_