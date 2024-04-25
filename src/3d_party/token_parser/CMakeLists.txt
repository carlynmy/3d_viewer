cmake_minimum_required(VERSION 3.5)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SOURCE_LIB 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/token_parser.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/token_parser.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/token.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/token.cc
)

add_library(token_parser STATIC ${SOURCE_LIB})
