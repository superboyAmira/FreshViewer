#include <gtest/gtest.h>

#include <string>
#include <iostream>

#include "../Models/model_scene.h"

TEST(TestParserFile, ParserFileFirst) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/cube.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(24, fac.GetVertices()->size());
  ASSERT_EQ(72, line->size());
}

// TEST(TestParserFile, ParserFileFirst) {
//     std::string file = "/home/superboy/FreshViewer/src/ObjExamples/cube.obj";
//     s21::ModelScene fac;
//     auto i = fac.LoadScene(file);
//     std::vector<double>* vec = fac.GetVertices();
//     i = fac.RotateScene(3, 0, 0);
//     EXPECT_TRUE(i.IsSuccess());
//     ASSERT_EQ()
//     ASSERT_EQ(24, fac.GetVertices()->size());
//     ASSERT_EQ(72, fac.GetLines()->size());
// }

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
