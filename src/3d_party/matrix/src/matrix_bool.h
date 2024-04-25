// matrix cpecialisation to bool

#ifndef S21_MATRIX_OOP_MATRIX_BOOL_H_
#define S21_MATRIX_OOP_MATRIX_BOOL_H_

#include "matrix.h"

namespace s21 {

template <>
typename Matrix<bool>::pointer Matrix<bool>::GetData();

template <>
typename Matrix<bool>::const_pointer Matrix<bool>::GetData() const;

}  // namespace s21

#endif  // S21_MATRIX_OOP_MATRIX_BOOL_H_
