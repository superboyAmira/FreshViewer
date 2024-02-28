#ifndef SRC_MODELS_EDGE_H_
#define SRC_MODELS_EDGE_H_

#include "vertex.h"

namespace s21 {
    class Edge {
        public:
            void SetBegin(Vertex* begin) noexcept { begin_ = begin; };
            void SetEnd(Vertex* end) noexcept { end_ = end; };
            void clear() noexcept {
                begin_ = nullptr;
                end_ = nullptr;
            };

            Vertex* GetBegin() const noexcept { return begin_; };

            Vertex* GetEnd() const noexcept { return end_; };
            
        private:
            Vertex* begin_;
            Vertex* end_;
    };
}

#endif  //  SRC_MODELS_EDGE_H_