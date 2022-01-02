cmake_minimum_required(VERSION 3.0.0)
project(BusinessStory VERSION 1.0.0)

add_subdirectory(src/accounting)
include_directories(src/accounting)
add_executable(accounting_unit_test accounting_unit_test.cpp)
target_link_libraries(accounting_unit_test PRIVATE accounting_lib)