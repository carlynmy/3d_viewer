#include <gtest/gtest.h>

#include <cmath>
#include <string>
#include <vector>

#include "model/view_object/data_parser/parser_obj.h"
#include "model/view_object/view_object_data.h"

struct TestModelObjectDataParserData {
  std::string filename;
  s21::ViewObjectData exp_data_;
  s21::ViewObjectDataParserOBJ::ReturnCode code_;
};

class TestModelObjectDataParser : public testing::TestWithParam<int> {
 public:
  static int count_;
  static std::vector<TestModelObjectDataParserData> data_;

  static void SetUpTestSuite();
};

int TestModelObjectDataParser::count_ = 16;
std::vector<TestModelObjectDataParserData> TestModelObjectDataParser::data_ =
    std::vector<TestModelObjectDataParserData>();

void TestModelObjectDataParser::SetUpTestSuite() {
  data_.reserve(count_);

  s21::ViewObjectData d2, d3, d4, d5, d6, d7, d8;
  s21::ViewObjectData d9, d10, d11, d12, d13, d14, d15, d16;

  d2.SetName("empty.obj");
  d2.SetVerticesStorageType(s21::ViewObjectData::kVerticesStorageTypeVertices);
  d2.SetMaxVertex(0);

  d3.SetName("Cube");
  d3.SetVerticesStorageType(s21::ViewObjectData::kVerticesStorageTypeVertices);
  d3.SetVertices({1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1,
                  1, 1,  -1, 1, 1,  1, -1, 1,  1, -1, 1,  -1});
  d3.SetFacesTriangle({1, 2, 3, 7, 6, 5, 4, 5, 1, 5, 6, 2, 2, 6, 7, 0, 3, 7,
                       0, 1, 3, 4, 7, 5, 0, 4, 1, 1, 5, 2, 3, 2, 7, 4, 0, 7});
  d3.SetMaxVertex(1);

  d4.SetName("Cube");
  d4.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTexture);
  d4.SetVertices(
      {1,  -1, 1,  1,        0.333333, -1, -1, 1,  1,        0.666667,
       -1, -1, -1, 0.666667, 0.666667, -1, 1,  -1, 1,        0.333333,
       -1, 1,  1,  0.666667, 0.333333, 1,  1,  1,  0.666667, 0});
  std::vector<uint32_t> d4f(6);
  for (int i = 0; i < 6; ++i) d4f[i] = i;
  d4.SetFacesTriangle(d4f);
  d4.SetMaxVertex(1);

  d5.SetName("Cube");
  d5.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesNormale);
  d5.SetVertices({1,  -1, 1,  0, -1, 0, -1, -1, 1,  0, -1, 0,
                  -1, -1, -1, 0, -1, 0, -1, 1,  -1, 0, 1,  0,
                  -1, 1,  1,  0, 1,  0, 1,  1,  1,  0, 1,  0});
  std::vector<uint32_t> d5f(6);
  for (int i = 0; i < 6; ++i) d5f[i] = i;
  d5.SetFacesTriangle(d5f);
  d5.SetMaxVertex(1);

  d6.SetName("Cube");
  d6.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTextureNormale);
  d6.SetMaxVertex(1);
  d6.SetVertices({1,  -1, 1,  1,        0.333333, 0, -1, 0,
                  -1, -1, 1,  1,        0.666667, 0, -1, 0,
                  -1, -1, -1, 0.666667, 0.666667, 0, -1, 0,
                  -1, 1,  -1, 1,        0.333333, 0, 1,  0,
                  -1, 1,  1,  0.666667, 0.333333, 0, 1,  0,
                  1,  1,  1,  0.666667, 0,        0, 1,  0});
  std::vector<uint32_t> d6f(6);
  for (int i = 0; i < 6; ++i) d6f[i] = i;
  d6.SetFacesTriangle(d6f);

  d7 = d6;

  d8 = d6;

  d9.SetName("Cube");
  d9.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTextureNormale);
  d9.SetMaxVertex(1);
  d9.SetVertices({
      1,  -1, 1,  1,        0.333333, 0, -1, 0,
      -1, -1, 1,  1,        0.666667, 0, -1, 0,
      -1, -1, -1, 0.666667, 0.666667, 0, -1, 0,
      -1, 1,  -1, 1,        0.333333, 0, 1,  0,
      -1, 1,  1,  0.666667, 0.333333, 0, 1,  0,
      1,  1,  1,  0.666667, 0,        0, 1,  0,
      -1, 1,  1,  0.666667, 0.333333, 0, 1,  0,
      1,  1,  1,  0.666667, 0,        0, 1,  0,
      -1, 1,  -1, 1,        0.333333, 0, 1,  0,

  });
  d9.SetFacesTriangle({0, 1, 2});
  d9.SetFacesPoint({3, 4, 5, 6, 7, 8});

  d10.SetName("Cube");
  d10.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesNormale);
  d10.SetMaxVertex(1);
  d10.SetVertices({
      1,  -1, 1,  0, -1, 0, -1, -1, 1, 0, -1, 0, -1, -1, -1, 0, -1, 0,
      -1, 1,  -1, 0, 1,  0, -1, 1,  1, 0, 1,  0, 1,  1,  1,  0, 1,  0,
      -1, 1,  1,  0, 1,  0, 1,  1,  1, 0, 1,  0, -1, 1,  -1, 0, 1,  0,

  });
  d10.SetFacesTriangle({0, 1, 2});
  d10.SetFacesPoint({3, 4, 5, 6, 7, 8});

  d11.SetName("Cube");
  d11.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTexture);
  d11.SetMaxVertex(1);
  d11.SetVertices({
      1,  -1, 1,  1,        0.333333, -1, -1, 1,  1,        0.666667,
      -1, -1, -1, 0.666667, 0.666667, -1, 1,  -1, 1,        0.333333,
      -1, 1,  1,  0.666667, 0.333333, 1,  1,  1,  0.666667, 0,
      -1, 1,  1,  0.666667, 0.333333, 1,  1,  1,  0.666667, 0,
      -1, 1,  -1, 1,        0.333333,

  });
  d11.SetFacesTriangle({0, 1, 2});
  d11.SetFacesPoint({3, 4, 5, 6, 7, 8});

  d12.SetName("Cube");
  d12.SetVerticesStorageType(s21::ViewObjectData::kVerticesStorageTypeVertices);
  d12.SetMaxVertex(1);
  d12.SetVertices({1, -1, -1, 1, -1, 1,  -1, -1, 1,  -1, -1, -1, 1,
                   1, -1, 1,  1, 1,  -1, 1,  1,  -1, 1,  -1

  });
  d12.SetFacesTriangle({1, 2, 3});
  d12.SetFacesPoint({7, 6, 5, 6, 5, 7});

  d13.SetName("Cube");
  d13.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTextureNormale);
  d13.SetMaxVertex(1);
  d13.SetVertices({
      1,  -1, 1,  1,        0.333333, 0, -1, 0,
      -1, -1, 1,  1,        0.666667, 0, -1, 0,
      -1, -1, -1, 0.666667, 0.666667, 0, -1, 0,
      -1, 1,  -1, 1,        0.333333, 0, 1,  0,
      -1, 1,  1,  0.666667, 0.333333, 0, 1,  0,
      -1, 1,  1,  0.666667, 0.333333, 0, 1,  0,
      1,  1,  1,  0.666667, 0,        0, 1,  0,
      1,  1,  1,  0.666667, 0,        0, 1,  0,
      -1, 1,  -1, 1,        0.333333, 0, 1,  0,

  });
  d13.SetFacesTriangle({0, 1, 2});
  d13.SetFacesLine({3, 4, 5, 6, 7, 8});

  d14.SetName("Cube");
  d14.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesTexture);
  d14.SetMaxVertex(1);
  d14.SetVertices({
      1,  -1, 1,  1,        0.333333, -1, -1, 1,  1,        0.666667,
      -1, -1, -1, 0.666667, 0.666667, -1, 1,  -1, 1,        0.333333,
      -1, 1,  1,  0.666667, 0.333333, -1, 1,  1,  0.666667, 0.333333,
      1,  1,  1,  0.666667, 0,        1,  1,  1,  0.666667, 0,
      -1, 1,  -1, 1,        0.333333,

  });
  d14.SetFacesTriangle({0, 1, 2});
  d14.SetFacesLine({3, 4, 5, 6, 7, 8});

  d15.SetName("Cube");
  d15.SetVerticesStorageType(
      s21::ViewObjectData::kVerticesStorageTypeVerticesNormale);
  d15.SetMaxVertex(1);
  d15.SetVertices({
      1,  -1, 1,  0, -1, 0, -1, -1, 1, 0, -1, 0, -1, -1, -1, 0, -1, 0,
      -1, 1,  -1, 0, 1,  0, -1, 1,  1, 0, 1,  0, -1, 1,  1,  0, 1,  0,
      1,  1,  1,  0, 1,  0, 1,  1,  1, 0, 1,  0, -1, 1,  -1, 0, 1,  0,

  });
  d15.SetFacesTriangle({0, 1, 2});
  d15.SetFacesLine({3, 4, 5, 6, 7, 8});

  d16.SetName("Cube");
  d16.SetVerticesStorageType(s21::ViewObjectData::kVerticesStorageTypeVertices);
  d16.SetMaxVertex(1);
  d16.SetVertices({1, -1, -1, 1, -1, 1,  -1, -1, 1,  -1, -1, -1, 1,
                   1, -1, 1,  1, 1,  -1, 1,  1,  -1, 1,  -1

  });
  d16.SetFacesTriangle({1, 2, 3});
  d16.SetFacesLine({7, 6, 6, 5, 5, 7});

  data_.push_back({"asd", {}, s21::ViewObjectDataParser::kCodeFileDontOpen});
  data_.push_back(
      {"tests/model/empty.obj", d2, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back(
      {"tests/model/cube_v.obj", d3, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back(
      {"tests/model/cube_vt.obj", d4, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back(
      {"tests/model/cube_vn.obj", d5, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back(
      {"tests/model/cube_all.obj", d6, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back(
      {"tests/model/cube_all_neg.obj", d7, s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_with_errs.obj", d8,
                   s21::ViewObjectDataParser::kCodeOk});

  data_.push_back({"tests/model/cube_all_points.obj", d9,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_vn_points.obj", d10,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_vt_points.obj", d11,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_v_points.obj", d12,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_all_lines.obj", d13,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_vn_lines.obj", d15,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_vt_lines.obj", d14,
                   s21::ViewObjectDataParser::kCodeOk});
  data_.push_back({"tests/model/cube_v_lines.obj", d16,
                   s21::ViewObjectDataParser::kCodeOk});
}

template <typename T>
bool VecEq(const std::vector<T>& a, const std::vector<T>& b) {
  if (a.size() != b.size()) return false;

  auto ai = a.begin();
  auto bi = b.begin();

  while (ai != a.end()) {
    if (*ai != *bi) return false;
    ++ai;
    ++bi;
  }

  return true;
}

template <>
bool VecEq(const std::vector<float>& a, const std::vector<float>& b) {
  if (a.size() != b.size()) return false;

  auto ai = a.begin();
  auto bi = b.begin();

  while (ai != a.end()) {
    if (std::abs(*ai - *bi) > 1e-5) return false;
    ++ai;
    ++bi;
  }

  return true;
}

TEST_P(TestModelObjectDataParser, Common) {
  int num_test = this->GetParam();
  TestModelObjectDataParserData& test_data =
      TestModelObjectDataParser::data_[num_test];

  s21::ViewObjectData object_data;
  s21::ViewObjectDataParserOBJ parser;
  s21::ViewObjectDataParserOBJ::ReturnCode code =
      parser.Parse(test_data.filename, object_data);

  ASSERT_EQ(code, test_data.code_);
  if (code != s21::ViewObjectDataParserOBJ::ReturnCode::kCodeOk) return;

  ASSERT_EQ(object_data.GetName(), test_data.exp_data_.GetName());
  ASSERT_EQ(object_data.GetVerticesStorageType(),
            test_data.exp_data_.GetVerticesStorageType());
  ASSERT_TRUE(std::abs(object_data.GetMaxVertex() -
                       test_data.exp_data_.GetMaxVertex()) <= 1e-5);

  ASSERT_TRUE(
      VecEq(object_data.GetVertices(), test_data.exp_data_.GetVertices()));
  ASSERT_TRUE(
      VecEq(object_data.GetFacesPoint(), test_data.exp_data_.GetFacesPoint()));
  ASSERT_TRUE(
      VecEq(object_data.GetFacesLine(), test_data.exp_data_.GetFacesLine()));
  ASSERT_TRUE(VecEq(object_data.GetFacesTriangle(),
                    test_data.exp_data_.GetFacesTriangle()));
}

INSTANTIATE_TEST_SUITE_P(My, TestModelObjectDataParser,
                         testing::Range(0, TestModelObjectDataParser::count_));
