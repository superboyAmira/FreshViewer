#ifndef SRC_MODELS_FACADE_H_
#define SRC_MODELS_FACADE_H_

#include "file_reader.h"
#include "scene.h"

namespace s21
{
    class Facade {
    private:
        BaseFileReader file_reader_;
        Scene scene_;
        SceneDrawerBase scene_drawer_;
    };
} // namespace s21


#endif  // SRC_MODELS_FACADE_H_