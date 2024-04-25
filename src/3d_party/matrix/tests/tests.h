
#ifndef MATRIX_TESTS_TEST_H_
#define MATRIX_TESTS_TEST_H_

#include <gtest/gtest.h>

#include <vector>

#include "matrix.h"
#include "user_class.h"

template <typename T>
struct TestsMatrixData {
  typename s21::Matrix<T>::size_type rows_;
  typename s21::Matrix<T>::size_type cols_;
  std::vector<T> data_;
};

template <typename T>
class TestsMatrix : public testing::Test {
 public:
  static TestsMatrixData<T> data_null_;
  static TestsMatrixData<T> data_1x1_;
  static T det_1x1_;
  static TestsMatrixData<T> data_1x1_2_;
  static TestsMatrixData<T> data_1x1_sum_;
  static TestsMatrixData<T> data_1x1_sub_;
  static TestsMatrixData<T> data_1x1_mul_;
  static TestsMatrixData<T> data_1x1_inversed_;
  static TestsMatrixData<T> data_2x2_;
  static T det_2x2_;
  static TestsMatrixData<T> data_2x2_2_;
  static TestsMatrixData<T> data_2x2_sum_;
  static TestsMatrixData<T> data_2x2_sub_;
  static TestsMatrixData<T> data_2x2_mul_;
  static TestsMatrixData<T> data_2x2_transposed_;
  static TestsMatrixData<T> data_2x2_inversed_;
  static TestsMatrixData<T> data_2x2_complements_;
  static TestsMatrixData<T> data_3x3_;
  static T det_3x3_;
  static TestsMatrixData<T> data_3x3_2_;
  static TestsMatrixData<T> data_3x3_sum_;
  static TestsMatrixData<T> data_3x3_sub_;
  static TestsMatrixData<T> data_3x3_mul_;
  static TestsMatrixData<T> data_3x3_transposed_;
  static TestsMatrixData<T> data_3x3_inversed_;
  static TestsMatrixData<T> data_3x3_complements_;
  static TestsMatrixData<T> data_3x3_cut_0_0_;
  static TestsMatrixData<T> data_3x3_cut_1_2_;
  static TestsMatrixData<T> data_3x3_cut_2_1_;
  static TestsMatrixData<T> data_3x3_cut_2_2_;
  static TestsMatrixData<T> data_3x3_zero_det_;
  static TestsMatrixData<T> data_3x2_;
  static TestsMatrixData<T> data_3x2_2_;
  static TestsMatrixData<T> data_3x2_sum_;
  static TestsMatrixData<T> data_3x2_sub_;
  static TestsMatrixData<T> data_3x2_transposed_;
  static TestsMatrixData<T> data_2x1_;
  static TestsMatrixData<T> data_2x1_2_;
  static TestsMatrixData<T> data_2x1_sum_;
  static TestsMatrixData<T> data_2x1_sub_;
  static TestsMatrixData<T> data_2x1_transposed_;
  static TestsMatrixData<T> data_3x2_2x1_mul_;

  static bool MatrixEq(const s21::Matrix<T>& matrix,
                       const TestsMatrixData<T>& data);

  static s21::Matrix<T> FromData(const TestsMatrixData<T>& data);
};

template <typename T>
bool TestsMatrix<T>::MatrixEq(const s21::Matrix<T>& matrix,
                              const TestsMatrixData<T>& data) {
  if (matrix.GetRows() != data.rows_ || matrix.GetCols() != data.cols_)
    return false;

  auto data_iter = data.data_.begin();
  for (typename s21::Matrix<T>::size_type i = 0; i < matrix.GetRows(); ++i) {
    for (typename s21::Matrix<T>::size_type j = 0; j < matrix.GetCols(); ++j) {
      if (matrix(i, j) != *data_iter) return false;
      ++data_iter;
    }
  }

  return true;
}

template <typename T>
s21::Matrix<T> TestsMatrix<T>::FromData(const TestsMatrixData<T>& data) {
  s21::Matrix<T> matrix(data.rows_, data.cols_);

  auto data_iter = data.data_.begin();
  for (typename s21::Matrix<T>::size_type i = 0; i < matrix.GetRows(); ++i) {
    for (typename s21::Matrix<T>::size_type j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = *data_iter;
      ++data_iter;
    }
  }

  return matrix;
}

template <typename T>
class TestsMatrixConstructor : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixComparator : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixElementAccess : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixElementAccessHasMethodData : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixElementAccessNoMethodData : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixModifiers : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixArithmetic : public TestsMatrix<T> {};
template <typename T>
class TestsMatrixFunctions : public TestsMatrix<T> {};

using TestsMatrixConstructorTypes =
    ::testing::Types<int, float, bool, UserClass>;
using TestsMatrixComparatorTypes =
    ::testing::Types<int, float, bool, UserClass>;
using TestsMatrixElementAccessTypes =
    ::testing::Types<int, float, bool, UserClass>;
using TestsMatrixElementAccessHasMethodDataTypes =
    ::testing::Types<int, float, UserClass>;
using TestsMatrixElementAccessNoMethodDataTypes = ::testing::Types<bool>;
using TestsMatrixModifiersTypes = ::testing::Types<int, float, bool, UserClass>;
using TestsMatrixArithmeticTypes =
    ::testing::Types<int, float, bool, UserClass>;
using TestsMatrixFunctionsTypes = ::testing::Types<int, float, bool, UserClass>;

TYPED_TEST_SUITE(TestsMatrixConstructor, TestsMatrixConstructorTypes);
TYPED_TEST_SUITE(TestsMatrixComparator, TestsMatrixComparatorTypes);
TYPED_TEST_SUITE(TestsMatrixElementAccess, TestsMatrixElementAccessTypes);
TYPED_TEST_SUITE(TestsMatrixElementAccessHasMethodData,
                 TestsMatrixElementAccessHasMethodDataTypes);
TYPED_TEST_SUITE(TestsMatrixElementAccessNoMethodData,
                 TestsMatrixElementAccessNoMethodDataTypes);
TYPED_TEST_SUITE(TestsMatrixModifiers, TestsMatrixModifiersTypes);
TYPED_TEST_SUITE(TestsMatrixArithmetic, TestsMatrixArithmeticTypes);
TYPED_TEST_SUITE(TestsMatrixFunctions, TestsMatrixFunctionsTypes);

#endif  // MATRIX_TESTS_TEST_H_
