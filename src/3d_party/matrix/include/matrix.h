// Matrix

#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <string>
#include <vector>

namespace s21 {

/// @brief class Matrix
/// @tparam T value type
template <typename T>
class Matrix {
 public:
  using value_type = typename std::vector<T>::value_type;
  using size_type = typename std::vector<T>::size_type;
  using pointer = typename std::vector<T>::pointer;
  using const_pointer = typename std::vector<T>::const_pointer;
  using reference = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;

  // ----------------------------------------------------------------------- //
  //                              Constructors                               //
  // ----------------------------------------------------------------------- //

  /// @brief Construct 0x0 matrix
  Matrix();

  /// @brief Construct matrix with rows and cols size. New data will be set to
  /// value
  /// @warning if rows or cols <= 0, construct 0x0 matrix
  Matrix(size_type rows, size_type cols, const_reference value = value_type(0));

  Matrix(const Matrix& other) = default;
  Matrix(Matrix&& other) noexcept = default;
  Matrix& operator=(const Matrix& other) = default;
  Matrix& operator=(Matrix&& other) noexcept = default;

  virtual ~Matrix();

  // ----------------------------------------------------------------------- //
  //                               Comparator                                //
  // ----------------------------------------------------------------------- //

  /// @brief Returns true if matrix have same size and all items are equal.
  /// Otherwise returns false.
  bool EqMatrix(const Matrix& other) const;

  /// @brief Returns true if matrix have same size and all items are equal.
  /// Otherwise returns false.
  bool operator==(const Matrix& other) const;

  /// @brief Returns false if matrix have same size and all items are equal.
  /// Otherwise returns true.
  bool operator!=(const Matrix& other) const;

  // ----------------------------------------------------------------------- //
  //                             Element access                              //
  // ----------------------------------------------------------------------- //

  /// @brief Get referense to item in row col position.
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  reference At(size_type row, size_type col);

  /// @brief Get const_referense to item in row col position.
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  const_reference At(size_type row, size_type col) const;

  /// @brief Get referense to item in row col position.
  /// @warning undefined behavior if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  reference operator()(size_type row, size_type col);

  /// @brief Get const referense to item in row col position.
  /// @warning undefined behavior if row not in (0, GetRows()) or col not in (0,
  /// GetCols())
  const_reference operator()(size_type row, size_type col) const;

  /// @brief Returns pointer to the underlying array serving as element storage.
  /// @throw std::logic_error if value_type is bool.
  /// @warning Undefined behavior if access to data not in range[0, GetRows() *
  /// GetCols())
  pointer GetData();

  /// @brief Returns const_pointer to the underlying array serving as element
  /// storage.
  /// @throw std::logic_error if value_type is bool.
  /// @warning Undefined behavior if access to data not in range[0, GetRows() *
  /// GetCols())
  const_pointer GetData() const;

  // ----------------------------------------------------------------------- //
  //                               Modifiers                                 //
  // ----------------------------------------------------------------------- //

  /// @brief Set rows. if new rows is bigger, new data will be set to value. if
  /// new rows is lesser old data will lost.
  /// @warning if rows <= 0, set 0x0 matrix.
  /// @warning if GetCols() == 0, matrix will remain 0x0.
  void SetRows(size_type rows, const_reference value = value_type(0));

  /// @brief Set cols. if new cols is bigger, new data will be set to value. if
  /// new cols is lesser old data will lost.
  /// @warning if cols <= 0, set 0x0 matrix.
  /// @warning if GetRows() == 0, matrix will remain 0x0.
  void SetCols(size_type cols, const_reference value = value_type(0));

  /// @brief Set size. if new rows is bigger, new data will be set to value. if
  /// new rows is lesser old data will lost. if new cols is bigger, new data
  /// will value. if new cols is lesser old data will lost.
  /// @warning if rows <= 0, set 0x0 matrix.
  /// @warning if cols <= 0, set 0x0 matrix.
  void SetSize(size_type rows, size_type cols,
               const_reference value = value_type(0));

  // ----------------------------------------------------------------------- //
  //                               Capacity                                  //
  // ----------------------------------------------------------------------- //

  size_type GetRows() const;
  size_type GetCols() const;

  // ----------------------------------------------------------------------- //
  //                               Arithmetic                                //
  // ----------------------------------------------------------------------- //

  /// @brief Add matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this
  Matrix& SumMatrix(const Matrix& other);

  /// @brief Sub matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& SubMatrix(const Matrix& other);

  /// @brief Mul matrix to matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& MulMatrix(const Matrix& other);

  /// @brief Mul matrix to number.
  /// @warning If matrix size is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& MulNumber(const_reference num);

  /// @brief Return sum matrix.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  Matrix operator+(const Matrix& other) const;

  /// @brief Return sub matrix.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  Matrix operator-(const Matrix& other) const;

  /// @brief Return sub matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  /// @warning If matrix sizes is 0x0 nothing happend.
  Matrix operator*(const Matrix& other) const;

  /// @brief Mul matrix to value.
  /// @warning If matrix size is 0x0 nothing happend.
  Matrix operator*(const_reference value) const;

  /// @brief Add matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& operator+=(const Matrix& other);

  /// @brief Sub matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& operator-=(const Matrix& other);

  /// @brief Mul matrix to matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  /// @warning If matrix sizes is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& operator*=(const Matrix& other);

  /// @brief Mul matrix to number.
  /// @warning If matrix size is 0x0 nothing happend.
  /// @return reference to this.
  Matrix& operator*=(const_reference value);

  // ----------------------------------------------------------------------- //
  //                               Functions                                 //
  // ----------------------------------------------------------------------- //

  /// @brief Calc determinant.
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if matrix size is 0x0.
  value_type Determinant() const;

  /// @brief Transpose matrix.
  /// @return reference to this.
  Matrix& Transpose();

  /// @brief Get transposed matrix
  Matrix GetTransposed();

  /// @brief Inverse matrix
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if determinant is zero.
  /// @throw std::logic_error if matrix size is 0x0.
  /// @return reference to this.
  Matrix& Inverse();

  /// @brief Get inversed matrix.
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if determinant is zero.
  /// @throw std::logic_error if matrix size is 0x0.
  Matrix GetInversed() const;

  /// @brief Return complements matrix
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if matrix size is 0x0.
  /// @throw std::logic_error if matrix size is 1x1.
  Matrix CalcComplements() const;

  /// @brief Remove row row, column col. The result will be a matrix dimension
  /// (GetRows() - 1, GetCols() - 1).
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  /// @throw std::logic_error if matrix size is 0x0.
  /// @warning if one of cols or rows become zero, result matrix will be 0x0.
  /// @return reference to this.
  Matrix& CutMatrix(size_type row, size_type col);

  /// @brief Get new matrix with removed row row, column col. The result will be
  /// a matrix dimension (GetRows() - 1, GetCols() - 1).
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  /// @throw std::logic_error if matrix size is 0x0.
  /// @warning if one of cols or rows become zero, result matrix will be 0x0.
  Matrix GetCutedMatrix(size_type row, size_type col) const;

 private:
  static const std::string kStrErrorOutOfRange_;
  static const std::string kStrErrorCantGetData_;
  static const std::string kStrErrorDiffSizes_;
  static const std::string kStrErrorInvalidSizes_;
  static const std::string kStrErrorZeroDeterminant_;
  static const std::string kStrErrorMatrixNotSquare_;
  static const std::string kStrErrorEmptyMatrix_;

  value_type AlgComplement(size_type row, size_type col) const;
  static bool IsEven(size_type val);

  size_type rows_, cols_;
  std::vector<value_type> matrix_;
};

/// @brief Mul matrix to value.
template <typename T>
Matrix<T> operator*(typename Matrix<T>::const_reference value,
                    const Matrix<T>& matrix);

}  // namespace s21

#include "../src/matrix.inc"
#include "../src/matrix_bool.h"

#endif  // S21_MATRIX_OOP_H_
