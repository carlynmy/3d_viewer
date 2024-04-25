#include "tests.h"

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// ------------------------------------------------------------------------- //
//                                 int data                                  //
// ------------------------------------------------------------------------- //

template <>
TestsMatrixData<int> TestsMatrix<int>::data_null_ = {0, 0, {}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_ = {1, 1, {2}};
template <>
int TestsMatrix<int>::det_1x1_ = 2;
template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_2_ = {1, 1, {1}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_sum_ = {1, 1, {3}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_sub_ = {1, 1, {1}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_mul_ = {1, 1, {2}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_1x1_inversed_ = {1, 1, {0}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_ = {2, 2, {1, 2, 3, 4}};
template <>
int TestsMatrix<int>::det_2x2_ = -2;
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_2_ = {2, 2, {-1, -2, 3, 4}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_sum_ = {2, 2, {0, 0, 6, 8}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_sub_ = {2, 2, {2, 4, 0, 0}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_mul_ = {2, 2, {5, 6, 9, 10}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_transposed_ = {
    2, 2, {1, 3, 2, 4}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_inversed_ = {
    2, 2, {0, 0, 0, 0}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x2_complements_ = {
    2, 2, {4, -3, -2, 1}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_ = {
    3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 8}};
template <>
int TestsMatrix<int>::det_3x3_ = 3;
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_2_ = {
    3, 3, {-1, -2, -3, -4, -5, -6, -7, -8, -8}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_sum_ = {
    3, 3, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_sub_ = {
    3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 16}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_mul_ = {
    3, 3, {-30, -36, -39, -66, -81, -90, -95, -118, -133}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_transposed_ = {
    3, 3, {1, 4, 7, 2, 5, 8, 3, 6, 8}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_inversed_ = {
    3, 3, {-0, 0, -0, 0, -0, 0, -0, 0, -0}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_complements_ = {
    3, 3, {-8, 10, -3, 8, -13, 6, -3, 6, -3}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_cut_0_0_ = {2, 2, {5, 6, 8, 8}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_cut_1_2_ = {2, 2, {1, 2, 7, 8}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_cut_2_1_ = {2, 2, {1, 3, 4, 6}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_cut_2_2_ = {2, 2, {1, 2, 4, 5}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x3_zero_det_ = {
    3, 3, {0, 0, 0, 12, 123, 22, 21, -2, -2, -2}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_ = {3, 2, {1, 2, 3, 4, 5, 6}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_2_ = {
    3, 2, {-1, -2, -3, -4, -5, -6}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_sum_ = {
    3, 2, {0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_sub_ = {
    3, 2, {2, 4, 6, 8, 10, 12}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_transposed_ = {
    2, 3, {1, 3, 5, 2, 4, 6}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x1_ = {2, 1, {1, 2}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x1_2_ = {2, 1, {3, 4}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x1_sum_ = {2, 1, {4, 6}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x1_sub_ = {2, 1, {-2, -2}};
template <>
TestsMatrixData<int> TestsMatrix<int>::data_2x1_transposed_ = {1, 2, {1, 2}};

template <>
TestsMatrixData<int> TestsMatrix<int>::data_3x2_2x1_mul_ = {3, 1, {5, 11, 17}};

// ------------------------------------------------------------------------- //
//                                float data                                 //
// ------------------------------------------------------------------------- //

template <>
TestsMatrixData<float> TestsMatrix<float>::data_null_ = {0, 0, {}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_ = {1, 1, {2}};
template <>
float TestsMatrix<float>::det_1x1_ = 2;
template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_2_ = {1, 1, {1}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_sum_ = {1, 1, {3}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_sub_ = {1, 1, {1}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_mul_ = {1, 1, {2}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_1x1_inversed_ = {1, 1, {0.5}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_ = {2, 2, {1, 2, 3, 4}};
template <>
float TestsMatrix<float>::det_2x2_ = -2;
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_2_ = {2, 2, {-1, -2, 3, 4}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_sum_ = {2, 2, {0, 0, 6, 8}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_sub_ = {2, 2, {2, 4, 0, 0}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_mul_ = {
    2, 2, {5, 6, 9, 10}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_transposed_ = {
    2, 2, {1, 3, 2, 4}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_inversed_ = {
    2, 2, {-2, 1, 1.5, -0.5}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x2_complements_ = {
    2, 2, {4, -3, -2, 1}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_ = {
    3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 8}};
template <>
float TestsMatrix<float>::det_3x3_ = 3;
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_2_ = {
    3, 3, {-1, -2, -3, -4, -5, -6, -7, -8, -8}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_sum_ = {
    3, 3, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_sub_ = {
    3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 16}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_mul_ = {
    3, 3, {-30, -36, -39, -66, -81, -90, -95, -118, -133}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_transposed_ = {
    3, 3, {1, 4, 7, 2, 5, 8, 3, 6, 8}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_inversed_ = {
    3, 3, {-2.66666675, 2.66666675, -1, 3.33333349, -4.33333349, 2, -1, 2, -1}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_complements_ = {
    3, 3, {-8, 10, -3, 8, -13, 6, -3, 6, -3}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_cut_0_0_ = {
    2, 2, {5, 6, 8, 8}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_cut_1_2_ = {
    2, 2, {1, 2, 7, 8}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_cut_2_1_ = {
    2, 2, {1, 3, 4, 6}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_cut_2_2_ = {
    2, 2, {1, 2, 4, 5}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x3_zero_det_ = {
    3, 3, {0, 0, 0, 12, 123, 22, 21, -2, -2, -2}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_ = {
    3, 2, {1, 2, 3, 4, 5, 6}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_2_ = {
    3, 2, {-1, -2, -3, -4, -5, -6}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_sum_ = {
    3, 2, {0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_sub_ = {
    3, 2, {2, 4, 6, 8, 10, 12}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_transposed_ = {
    2, 3, {1, 3, 5, 2, 4, 6}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x1_ = {2, 1, {1, 2}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x1_2_ = {2, 1, {3, 4}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x1_sum_ = {2, 1, {4, 6}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x1_sub_ = {2, 1, {-2, -2}};
template <>
TestsMatrixData<float> TestsMatrix<float>::data_2x1_transposed_ = {
    1, 2, {1, 2}};

template <>
TestsMatrixData<float> TestsMatrix<float>::data_3x2_2x1_mul_ = {
    3, 1, {5, 11, 17}};

// ------------------------------------------------------------------------- //
//                                 bool data                                 //
// ------------------------------------------------------------------------- //

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_null_ = {0, 0, {}};

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_ = {1, 1, {true}};
template <>
bool TestsMatrix<bool>::det_1x1_ = true;
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_2_ = {1, 1, {false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_sum_ = {1, 1, {true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_sub_ = {1, 1, {true}};
;
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_mul_ = {1, 1, {false}};
;
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_1x1_inversed_ = {1, 1, {true}};
;

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_ = {
    2, 2, {true, false, true, true}};
template <>
bool TestsMatrix<bool>::det_2x2_ = true;
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_2_ = {
    2, 2, {true, false, false, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_sum_ = {
    2, 2, {true, false, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_sub_ = {
    2, 2, {false, false, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_mul_ = {
    2, 2, {true, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_transposed_ = {
    2, 2, {true, true, false, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_inversed_ = {
    2, 2, {true, false, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x2_complements_ = {
    2, 2, {true, true, false, true}};

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_ = {
    3, 3, {true, true, true, true, false, false, false, true, false}};
template <>
bool TestsMatrix<bool>::det_3x3_ = true;
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_2_ = {
    3, 3, {true, false, true, false, true, false, true, false, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_sum_ = {
    3, 3, {true, true, true, true, true, false, true, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_sub_ = {
    3, 3, {false, true, false, true, true, false, true, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_mul_ = {
    3, 3, {true, true, true, true, false, true, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_transposed_ = {
    3, 3, {true, true, false, true, false, true, true, false, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_inversed_ = {
    3, 3, {false, true, false, false, false, true, true, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_complements_ = {
    3, 3, {false, false, true, true, false, true, false, true, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_cut_0_0_ = {
    2, 2, {false, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_cut_1_2_ = {
    2, 2, {true, true, false, true}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_cut_2_1_ = {
    2, 2, {true, true, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_cut_2_2_ = {
    2, 2, {true, true, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x3_zero_det_ = {
    3, 3, {false, false, false, false, false, false, false, false, false}};

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_ = {
    3, 2, {true, true, true, false, false, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_2_ = {
    3, 2, {true, false, true, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_sum_ = {
    3, 2, {true, true, true, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_sub_ = {
    3, 2, {false, true, false, false, true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_transposed_ = {
    2, 3, {true, true, false, true, false, false}};

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x1_ = {2, 1, {true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x1_2_ = {2, 1, {true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x1_sum_ = {2, 1, {true, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x1_sub_ = {2, 1, {false, false}};
template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_2x1_transposed_ = {
    1, 2, {true, false}};

template <>
TestsMatrixData<bool> TestsMatrix<bool>::data_3x2_2x1_mul_ = {
    3, 1, {true, true, false}};

// ------------------------------------------------------------------------- //
//                              UserClass data                               //
// ------------------------------------------------------------------------- //

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_null_ = {0, 0, {}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_ = {1, 1, {2}};
template <>
UserClass TestsMatrix<UserClass>::det_1x1_ = 2;
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_2_ = {1, 1, {1}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_sum_ = {1, 1, {3}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_sub_ = {1, 1, {1}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_mul_ = {1, 1, {2}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_1x1_inversed_ = {
    1, 1, {0}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_ = {
    2, 2, {1, 2, 3, 4}};
template <>
UserClass TestsMatrix<UserClass>::det_2x2_ = -2;
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_2_ = {
    2, 2, {-1, -2, 3, 4}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_sum_ = {
    2, 2, {0, 0, 6, 8}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_sub_ = {
    2, 2, {2, 4, 0, 0}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_mul_ = {
    2, 2, {5, 6, 9, 10}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_transposed_ = {
    2, 2, {1, 3, 2, 4}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_inversed_ = {
    2, 2, {-0, 0, 0, 0}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x2_complements_ = {
    2, 2, {4, -3, -2, 1}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_ = {
    3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 8}};
template <>
UserClass TestsMatrix<UserClass>::det_3x3_ = 3;
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_2_ = {
    3, 3, {-1, -2, -3, -4, -5, -6, -7, -8, -8}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_sum_ = {
    3, 3, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_sub_ = {
    3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 16}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_mul_ = {
    3, 3, {-30, -36, -39, -66, -81, -90, -95, -118, -133}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_transposed_ = {
    3, 3, {1, 4, 7, 2, 5, 8, 3, 6, 8}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_inversed_ = {
    3, 3, {-0, 0, -0, 0, -0, 0, -0, 0, -0}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_complements_ = {
    3, 3, {-8, 10, -3, 8, -13, 6, -3, 6, -3}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_cut_0_0_ = {
    2, 2, {5, 6, 8, 8}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_cut_1_2_ = {
    2, 2, {1, 2, 7, 8}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_cut_2_1_ = {
    2, 2, {1, 3, 4, 6}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_cut_2_2_ = {
    2, 2, {1, 2, 4, 5}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x3_zero_det_ = {
    3, 3, {0, 0, 0, 12, 123, 22, 21, -2, -2, -2}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_ = {
    3, 2, {1, 2, 3, 4, 5, 6}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_2_ = {
    3, 2, {-1, -2, -3, -4, -5, -6}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_sum_ = {
    3, 2, {0, 0, 0, 0, 0, 0}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_sub_ = {
    3, 2, {2, 4, 6, 8, 10, 12}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_transposed_ = {
    2, 3, {1, 3, 5, 2, 4, 6}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x1_ = {2, 1, {1, 2}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x1_2_ = {2, 1, {3, 4}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x1_sum_ = {
    2, 1, {4, 6}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x1_sub_ = {
    2, 1, {-2, -2}};
template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_2x1_transposed_ = {
    1, 2, {1, 2}};

template <>
TestsMatrixData<UserClass> TestsMatrix<UserClass>::data_3x2_2x1_mul_ = {
    3, 1, {5, 11, 17}};
