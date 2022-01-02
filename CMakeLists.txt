cmake_minimum_required(VERSION 3.0.0)
project(BusinessStory VERSION 1.0.0)

add_subdirectory(src/accounting)
include_directories(src/accounting)

if (${BUILD_EXEC}=AccountingUT)
    add_executable(accounting_unit_test accounting_unit_test.cpp)
    set(CMAKE_BUILD_TYPE Debug)
    target_link_libraries(accounting_unit_test PRIVATE accounting_lib)
endif()

if (CMAKE_BUILD_TYPE=Debug)
    set_target_properties(accounting_unit_test PROPERTIES DEBUG_POSTFIX _d)
endif()
