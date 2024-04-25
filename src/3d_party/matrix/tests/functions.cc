// Matrix functions tests

#include <gtest/gtest.h>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixFunctions, TransposeNull) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_null_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_null_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose1x1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_1x1_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_1x1_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose2x2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x2_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_2x2_transposed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose3x3) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_transposed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose3x2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x2_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x2_transposed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose2x1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x1_);
  s21::Matrix<TypeParam> matrix_transposed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_2x1_transposed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  s21::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Inverse1x1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_1x1_);
  s21::Matrix<TypeParam> matrix_inversed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_1x1_inversed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  s21::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Inverse2x2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x2_);
  s21::Matrix<TypeParam> matrix_inversed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_2x2_inversed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  s21::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Inverse3x3) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_inversed =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_inversed_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  s21::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, InverseExceptionNull) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_null_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, InverseExceptionNotSquare) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x2_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, InverseExceptionDetZero) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_zero_det_);
  s21::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Complements2x2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x2_);
  s21::Matrix<TypeParam> matrix_complements =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_2x2_complements_);
  s21::Matrix<TypeParam> matrix_a = matrix.CalcComplements();

  ASSERT_EQ(matrix_complements, matrix_a);
}

TYPED_TEST(TestsMatrixFunctions, Complements3x3) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_complements =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_complements_);
  s21::Matrix<TypeParam> matrix_a = matrix.CalcComplements();

  ASSERT_EQ(matrix_complements, matrix_a);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsExceptionNull) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_null_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsException1x1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_1x1_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsExceptionNotSquare) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x2_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_0_0) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_cuted =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_cut_0_0_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(0, 0);
  s21::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(0, 0);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_1_2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_cuted =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_cut_1_2_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(1, 2);
  s21::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(1, 2);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_2_1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_cuted =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_cut_2_1_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(2, 1);
  s21::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(2, 1);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_2_2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  s21::Matrix<TypeParam> matrix_cuted =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_3x3_cut_2_2_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(2, 2);
  s21::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(2, 2);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, CutToZero) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x1_);
  s21::Matrix<TypeParam> matrix_cuted =
      TestsMatrixComparator<TypeParam>::FromData(
          TestsMatrixComparator<TypeParam>::data_null_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(0, 0);
  s21::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(0, 0);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, CutExceptionNull) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_null_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.CutMatrix(0, 0), std::logic_error);
  ASSERT_THROW(matrix.GetCutedMatrix(2, 2), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, CutExceptionOutOfRange) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);

  s21::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.CutMatrix(2, 56), std::logic_error);
  ASSERT_THROW(matrix.GetCutedMatrix(1241442, 123), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Determenant1x1) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_1x1_);
  TypeParam exp_det = TestsMatrixComparator<TypeParam>::det_1x1_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, Determenant2x2) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_2x2_);
  TypeParam exp_det = TestsMatrixComparator<TypeParam>::det_2x2_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, Determenant3x3) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x3_);
  TypeParam exp_det = TestsMatrixComparator<TypeParam>::det_3x3_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, DetermenantExceptionNull) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_null_);

  ASSERT_THROW(matrix.Determinant(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, DetermenantExceptionNotSquare) {
  s21::Matrix<TypeParam> matrix = TestsMatrixComparator<TypeParam>::FromData(
      TestsMatrixComparator<TypeParam>::data_3x2_);

  ASSERT_THROW(matrix.Determinant(), std::logic_error);
}
