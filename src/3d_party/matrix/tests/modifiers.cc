// Matrix modifiers tests

#include <gtest/gtest.h>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixModifiers, SetRowsBigger) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 5;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetRows(new_rows, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }

  for (typename s21::Matrix<TypeParam>::size_type i = rows; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetRowsLesser) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 1;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetRows(new_rows);

  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetRowsSame) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 3;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetRows(new_rows);

  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetRows0) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetRows(new_rows);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}

TYPED_TEST(TestsMatrixModifiers, SetRowsWithCols0) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_null_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetRows(115);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}

TYPED_TEST(TestsMatrixModifiers, SetColsBigger) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_cols = 5;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetCols(new_cols, value);
  ASSERT_EQ(rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }

    for (typename s21::Matrix<TypeParam>::size_type j = cols; j < new_cols;
         ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetColsLesser) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_cols = 2;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetCols(new_cols);
  ASSERT_EQ(rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetColsSame) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_cols = 3;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetCols(new_cols);
  ASSERT_EQ(rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetColsZero) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetCols(new_cols);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}

TYPED_TEST(TestsMatrixModifiers, SetColsWithRows0) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_null_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetCols(12412);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsSameColsSame) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 3;
  typename s21::Matrix<TypeParam>::size_type new_cols = 3;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsBiggerColsSame) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 5;
  typename s21::Matrix<TypeParam>::size_type new_cols = 3;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }

  for (typename s21::Matrix<TypeParam>::size_type i = rows; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsLesserColsSame) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 2;
  typename s21::Matrix<TypeParam>::size_type new_cols = 3;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsBiggerColsBigger) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 5;
  typename s21::Matrix<TypeParam>::size_type new_cols = 5;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }

    for (typename s21::Matrix<TypeParam>::size_type j = cols; j < new_cols;
         ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }

  for (typename s21::Matrix<TypeParam>::size_type i = rows; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsSameColsBigger) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 3;
  typename s21::Matrix<TypeParam>::size_type new_cols = 5;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }

    for (typename s21::Matrix<TypeParam>::size_type j = cols; j < new_cols;
         ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }

  for (typename s21::Matrix<TypeParam>::size_type i = rows; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsLesserColsBigger) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type cols = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 2;
  typename s21::Matrix<TypeParam>::size_type new_cols = 5;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }

    for (typename s21::Matrix<TypeParam>::size_type j = cols; j < new_cols;
         ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsSameColsLesser) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 3;
  typename s21::Matrix<TypeParam>::size_type new_cols = 2;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsBiggerColsLesser) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  typename s21::Matrix<TypeParam>::size_type rows = 3;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 5;
  typename s21::Matrix<TypeParam>::size_type new_cols = 2;
  TypeParam value = TypeParam(5);
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols, value);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }

  for (typename s21::Matrix<TypeParam>::size_type i = rows; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(value, new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRowsLesserColsLesser) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 2;
  typename s21::Matrix<TypeParam>::size_type new_cols = 2;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(new_rows, new_cols);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
  for (typename s21::Matrix<TypeParam>::size_type i = 0; i < new_rows; ++i) {
    for (typename s21::Matrix<TypeParam>::size_type j = 0; j < new_cols; ++j) {
      ASSERT_EQ(matrix(i, j), new_matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixModifiers, SetSizeRows0) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(0, 214);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}

TYPED_TEST(TestsMatrixModifiers, SetSizeCols0) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixModifiers<TypeParam>::data_3x3_;
  s21::Matrix<TypeParam> matrix =
      TestsMatrixModifiers<TypeParam>::FromData(data);
  typename s21::Matrix<TypeParam>::size_type new_rows = 0;
  typename s21::Matrix<TypeParam>::size_type new_cols = 0;
  s21::Matrix<TypeParam> new_matrix = matrix;

  new_matrix.SetSize(214, 0);
  ASSERT_EQ(new_rows, new_matrix.GetRows());
  ASSERT_EQ(new_cols, new_matrix.GetCols());
}
