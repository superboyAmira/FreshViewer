#ifndef SRC_MODELS_EDGE_H_
#define SRC_MODELS_EDGE_H_

#include "vertex.h"

namespace s21 {
    class Edge {
        public:
            void SetBegin(Vertex* begin) { begin_ = begin; };
            void SetEnd(Vertex* end) { end_ = end; };


            Vertex* GetBegin() const noexcept { return begin_; };

            Vertex* GetEnd() const noexcept { return end_; };
            
        private:
            Vertex* begin_;
            Vertex* end_;
    };
}

#endif  //  SRC_MODELS_EDGE_H_