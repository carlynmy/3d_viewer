cmake_minimum_required(VERSION 3.5)

project(matrix)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SOURCE_LIB
  ${CMAKE_CURRENT_SOURCE_DIR}/include/matrix.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.inc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix_bool.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix_bool.cc
)
  
set(SOURCE_TESTS
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/user_class.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/user_class.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/constructors.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/element_access.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/comparator.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/modifiers.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/arithmetics.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/functions.cc
)

SET(COVERAGE_FLAGS "" CACHE STRING "")
SET(WARNING_FLAGS "-Wall -Wextra -Werror -Wno-error=int-in-bool-context -Wno-int-in-bool-context" CACHE STRING "")
SET(STANDART_FLAGS "-std=c++17" CACHE STRING "")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS} ${WARNING_FLAGS} ${STANDART_FLAGS} ")

add_library(matrix STATIC ${SOURCE_LIB})

add_executable(matrix_tests ${SOURCE_TESTS})

target_link_libraries(
  matrix_tests
  gtest
  matrix
)
