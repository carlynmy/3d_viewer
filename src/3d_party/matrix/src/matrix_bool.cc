/// matrix specialization bool

#include <stdexcept>

#include "matrix.h"

namespace s21 {

template <>
typename Matrix<bool>::pointer Matrix<bool>::GetData() {
  throw std::logic_error(kStrErrorCantGetData_);
  return nullptr;
}

template <>
typename Matrix<bool>::const_pointer Matrix<bool>::GetData() const {
  throw std::logic_error(kStrErrorCantGetData_);
  return nullptr;
}

}  // namespace s21
