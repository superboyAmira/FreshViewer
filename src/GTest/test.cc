#include <gtest/gtest.h>

#include <string>
#include <iostream>

#include "../Models/model_scene.h"

TEST(TestParserFile, ParserFileFirst) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/cube.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  i = fac.RotateScene(1.0, 0.3, 54);
  i = fac.MoveScene(1.4, 54, 1.24253);
  i = fac.ScaleScene(2.4);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(24, fac.GetVertices()->size());
  ASSERT_EQ(72, line->size());
}

TEST(TestParserFile1, ParserFile2) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/cube.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(24, fac.GetVertices()->size());
  ASSERT_EQ(72, line->size());
}

TEST(TestParserFile2, ParserFile3) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/fish.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(1119, fac.GetVertices()->size());
  ASSERT_EQ(2688, line->size());
}

TEST(TestParserFile3, ParserFile3) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/characterlowpoly2.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(3213, fac.GetVertices()->size());
  ASSERT_EQ(8748, line->size());
}

TEST(TestParserFile4, ParserFile4) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/CasteliaCity.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_TRUE(i.IsSuccess());
  std::vector<int>* line = fac.GetLines();
  ASSERT_EQ(1091085, fac.GetVertices()->size());
  ASSERT_EQ(2217478, line->size());
}

TEST(TestParserFile5, ParserFile5) {
  std::string file = "/home/superboy/FreshViewer/src/ObjExamples/no.obj";
  s21::ModelScene fac;
  auto i = fac.LoadScene(file);
  EXPECT_FALSE(i.IsSuccess());
  // std::vector<int>* line = fac.GetLines();
  // ASSERT_EQ(0, fac.GetVertices()->size());
  // ASSERT_EQ(0, line->size());
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
