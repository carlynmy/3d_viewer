// Matrix comparator tests

#include <gtest/gtest.h>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixComparator, Equal) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixComparator<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix_a =
      TestsMatrixComparator<TypeParam>::FromData(data);
  s21::Matrix<TypeParam> matrix_b =
      TestsMatrixComparator<TypeParam>::FromData(data);

  ASSERT_TRUE(matrix_a.EqMatrix(matrix_b));
  ASSERT_TRUE(matrix_a == matrix_b);
  ASSERT_FALSE(matrix_a != matrix_b);
  ASSERT_TRUE(matrix_b.EqMatrix(matrix_a));
  ASSERT_TRUE(matrix_b == matrix_a);
  ASSERT_FALSE(matrix_b != matrix_a);
}

TYPED_TEST(TestsMatrixComparator, NotEqual) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixComparator<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix_a =
      TestsMatrixComparator<TypeParam>::FromData(data);
  s21::Matrix<TypeParam> matrix_b =
      TestsMatrixComparator<TypeParam>::FromData(data);
  matrix_b(1, 1) = matrix_a(1, 1) - TypeParam(1);

  ASSERT_FALSE(matrix_a.EqMatrix(matrix_b));
  ASSERT_FALSE(matrix_a == matrix_b);
  ASSERT_TRUE(matrix_a != matrix_b);
  ASSERT_FALSE(matrix_b.EqMatrix(matrix_a));
  ASSERT_FALSE(matrix_b == matrix_a);
  ASSERT_TRUE(matrix_b != matrix_a);
}

TYPED_TEST(TestsMatrixComparator, NotEqualSizes) {
  const TestsMatrixData<TypeParam>& data_a =
      TestsMatrixComparator<TypeParam>::data_3x3_;
  const TestsMatrixData<TypeParam>& data_b =
      TestsMatrixComparator<TypeParam>::data_3x2_;
  s21::Matrix<TypeParam> matrix_a =
      TestsMatrixComparator<TypeParam>::FromData(data_a);
  s21::Matrix<TypeParam> matrix_b =
      TestsMatrixComparator<TypeParam>::FromData(data_b);

  ASSERT_FALSE(matrix_a.EqMatrix(matrix_b));
  ASSERT_FALSE(matrix_a == matrix_b);
  ASSERT_TRUE(matrix_a != matrix_b);
  ASSERT_FALSE(matrix_b.EqMatrix(matrix_a));
  ASSERT_FALSE(matrix_b == matrix_a);
  ASSERT_TRUE(matrix_b != matrix_a);
}
