// Matrix

#include <stdexcept>
#include <utility>
#include <vector>

#include "matrix.h"

namespace s21 {

template <typename T>
const std::string Matrix<T>::kStrErrorOutOfRange_ = "Индекс за пределами";
template <typename T>
const std::string Matrix<T>::kStrErrorCantGetData_ =
    "Невозможно получить доступ к массиву";
template <typename T>
const std::string Matrix<T>::kStrErrorDiffSizes_ = "Матрицы разных размеров";
template <typename T>
const std::string Matrix<T>::kStrErrorInvalidSizes_ =
    "Неккоректные размеры матрицы";
template <typename T>
const std::string Matrix<T>::kStrErrorZeroDeterminant_ = "Детерменант 0";
template <typename T>
const std::string Matrix<T>::kStrErrorMatrixNotSquare_ =
    "Матрица не квадратная";
template <typename T>
const std::string Matrix<T>::kStrErrorEmptyMatrix_ =
    "Операция с нулевой матрицей";

// ------------------------------------------------------------------------- //
//                               Constructors                                //
// ------------------------------------------------------------------------- //

template <typename T>
Matrix<T>::Matrix() : Matrix(0, 0) {}

template <typename T>
Matrix<T>::Matrix(size_type rows, size_type cols, const_reference value) {
  if (rows <= 0 || cols <= 0) {
    rows = 0;
    cols = 0;
  }

  rows_ = rows;
  cols_ = cols;
  matrix_.resize(rows_ * cols_, value);
}

template <typename T>
Matrix<T>::~Matrix() {}

// ------------------------------------------------------------------------- //
//                                Comparator                                 //
// ------------------------------------------------------------------------- //

template <typename T>
bool Matrix<T>::EqMatrix(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    return false;

  for (size_type i = 0; i < GetRows(); ++i) {
    for (size_type j = 0; j < GetCols(); ++j) {
      if ((*this)(i, j) != other(i, j)) return false;
    }
  }

  return true;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& other) const {
  return this->EqMatrix(other);
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix& other) const {
  return !this->EqMatrix(other);
}

// ------------------------------------------------------------------------- //
//                             Element access                              //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::reference Matrix<T>::At(size_type row, size_type col) {
  if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  return this->operator()(row, col);
}

template <typename T>
typename Matrix<T>::const_reference Matrix<T>::At(size_type row,
                                                  size_type col) const {
  if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  return this->operator()(row, col);
}

template <typename T>
typename Matrix<T>::reference Matrix<T>::operator()(size_type row,
                                                    size_type col) {
  return matrix_[row * GetCols() + col];
}

template <typename T>
typename Matrix<T>::const_reference Matrix<T>::operator()(size_type row,
                                                          size_type col) const {
  return matrix_[row * GetCols() + col];
}

template <typename T>
typename Matrix<T>::pointer Matrix<T>::GetData() {
  return matrix_.data();
}

template <typename T>
typename Matrix<T>::const_pointer Matrix<T>::GetData() const {
  return matrix_.data();
}

// ------------------------------------------------------------------------- //
//                                Modifiers                                  //
// ------------------------------------------------------------------------- //

template <typename T>
void Matrix<T>::SetRows(size_type rows, const_reference value) {
  if (GetCols() == 0) return;
  if (rows <= 0) {
    rows_ = 0;
    cols_ = 0;
    matrix_.resize(0);
    return;
  }

  rows_ = rows;
  matrix_.resize(rows_ * cols_, value);
}

template <typename T>
void Matrix<T>::SetCols(size_type cols, const_reference value) {
  if (GetRows() == 0) return;
  if (cols <= 0) {
    rows_ = 0;
    cols_ = 0;
    matrix_.resize(0);
    return;
  }

  size_type copy_count = GetCols();
  if (cols < GetCols()) copy_count = cols;

  std::vector<value_type> new_matrix(GetRows() * cols, value);

  for (size_type row = 0; row < GetRows(); ++row) {
    for (size_type col = 0; col < copy_count; ++col)
      new_matrix[row * cols + col] = (*this)(row, col);
  }

  cols_ = cols;
  matrix_ = std::move(new_matrix);
}

template <typename T>
void Matrix<T>::SetSize(size_type rows, size_type cols, const_reference value) {
  if (rows <= 0 || cols <= 0) {
    rows_ = 0;
    cols_ = 0;
    matrix_.resize(0);
    return;
  }

  std::vector<value_type> new_matrix(rows * cols, value);
  size_type rows_copy_size = GetRows();
  size_type cols_copy_size = GetCols();
  if (rows < GetRows()) rows_copy_size = rows;
  if (cols < GetCols()) cols_copy_size = cols;

  for (size_type i = 0; i < rows_copy_size; ++i) {
    for (size_type j = 0; j < cols_copy_size; ++j) {
      new_matrix[i * cols + j] = (*this)(i, j);
    }
  }

  rows_ = rows;
  cols_ = cols;
  matrix_ = std::move(new_matrix);
}

// ------------------------------------------------------------------------- //
//                                Capacity                                   //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetRows() const {
  return rows_;
}

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetCols() const {
  return cols_;
}

// ------------------------------------------------------------------------- //
//                                Arithmetic                                 //
// ------------------------------------------------------------------------- //

template <typename T>
Matrix<T>& Matrix<T>::SumMatrix(const Matrix& other) {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::SubMatrix(const Matrix& other) {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::MulMatrix(const Matrix& other) {
  if (GetCols() != other.GetRows())
    throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix new_matrix(GetRows(), other.GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < other.GetCols(); j++) {
      value_type tmp_sum = value_type(0);
      for (size_type k = 0; k < GetCols(); k++)
        tmp_sum += (*this)(i, k) * other(k, j);
      new_matrix(i, j) = tmp_sum;
    }
  }

  *this = std::move(new_matrix);
  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::MulNumber(const_reference num) {
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) * num;
    }
  }

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  Matrix res(GetRows(), GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  Matrix res(GetRows(), GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
  if (GetCols() != other.GetRows())
    throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix res(GetRows(), other.GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < other.GetCols(); j++) {
      value_type tmp_sum = value_type(0);
      for (size_type k = 0; k < GetCols(); k++)
        tmp_sum += (*this)(i, k) * other(k, j);
      res(i, j) = tmp_sum;
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const_reference value) const {
  Matrix res(GetRows(), GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) * value;
    }
  }

  return res;
}

template <typename T>
Matrix<T> operator*(typename Matrix<T>::const_reference value,
                    const Matrix<T>& matrix) {
  Matrix<T> res(matrix.GetRows(), matrix.GetCols());
  for (typename Matrix<T>::size_type i = 0; i < matrix.GetRows(); i++) {
    for (typename Matrix<T>::size_type j = 0; j < matrix.GetCols(); j++) {
      res(i, j) = matrix(i, j) * value;
    }
  }

  return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other) {
  return this->SumMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other) {
  return this->SubMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& other) {
  return this->MulMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const_reference value) {
  return this->MulNumber(value);
}

// ------------------------------------------------------------------------- //
//                                Functions                                  //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::value_type Matrix<T>::Determinant() const {
  if (GetRows() != GetCols()) throw std::logic_error(kStrErrorMatrixNotSquare_);
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetRows() == 1) return (*this)(0, 0);

  value_type answer = value_type(0);
  for (size_type j = 0; j < GetRows(); j++)
    answer += (*this)(0, j) * AlgComplement(0, j);
  return answer;
}

template <typename T>
Matrix<T>& Matrix<T>::Transpose() {
  *this = std::move(GetTransposed());
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetTransposed() {
  Matrix new_matrix(GetCols(), GetRows());
  for (size_type i = 0; i < new_matrix.GetRows(); i++) {
    for (size_type j = 0; j < new_matrix.GetCols(); j++) {
      new_matrix(i, j) = (*this)(j, i);
    }
  }
  return new_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::Inverse() {
  *this = std::move(GetInversed());
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetInversed() const {
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetCols() == 1 && GetRows() == 1) {
    Matrix res(1, 1);
    res(0, 0) = value_type(1) / (*this)(0, 0);
    return res;
  }

  value_type det = Determinant();
  if (det == 0) throw std::logic_error(kStrErrorZeroDeterminant_);
  Matrix res = CalcComplements();
  res.Transpose();
  res.MulNumber(value_type(1) / det);

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::CalcComplements() const {
  if (GetRows() != GetCols()) throw std::logic_error(kStrErrorMatrixNotSquare_);
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetRows() == 1) throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix result_matrix(GetRows(), GetCols());
  for (size_type i = 0; i < GetRows(); i++) {
    for (size_type j = 0; j < GetCols(); j++) {
      result_matrix(i, j) = AlgComplement(i, j);
    }
  }

  return result_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::CutMatrix(size_type row, size_type col) {
  *this = std::move(GetCutedMatrix(row, col));
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetCutedMatrix(size_type row, size_type col) const {
  if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);

  Matrix res(GetRows() - 1, GetCols() - 1);

  for (size_type i = 0; i != row; ++i) {
    for (size_type j = 0; j != col; ++j) {
      res(i, j) = (*this)(i, j);
    }
  }

  for (size_type i = row; i != res.GetRows(); ++i) {
    for (size_type j = 0; j != col; ++j) {
      res(i, j) = (*this)(i + 1, j);
    }
  }

  for (size_type i = 0; i != row; ++i) {
    for (size_type j = col; j != res.GetCols(); ++j) {
      res(i, j) = (*this)(i, j + 1);
    }
  }

  for (size_type i = row; i != res.GetRows(); ++i) {
    for (size_type j = col; j != res.GetCols(); ++j) {
      res(i, j) = (*this)(i + 1, j + 1);
    }
  }

  return res;
}

template <typename T>
typename Matrix<T>::value_type Matrix<T>::AlgComplement(size_type row,
                                                        size_type col) const {
  Matrix cut_matrix = GetCutedMatrix(row, col);
  value_type minor = cut_matrix.Determinant();
  value_type alg_complement =
      (IsEven(row + col) ? value_type(1) : value_type(-1)) * minor;
  return alg_complement;
}

template <typename T>
bool Matrix<T>::IsEven(size_type val) {
  return (val % 2 == 0);
}

}  // namespace s21
