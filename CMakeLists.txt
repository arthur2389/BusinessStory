cmake_minimum_required(VERSION 3.0.0)
project(BusinessStory VERSION 1.0.0)

if (BUILD_EXEC STREQUAL AccountingUT)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(src/accounting)
include_directories(src/accounting)

set(UNIT_TEST FALSE)

if (BUILD_EXEC STREQUAL AccountingUT)
    message("Running cmake for accounting unit test")
    add_executable(accounting_unit_test accounting_unit_test.cpp)
    set_target_properties(accounting_unit_test PROPERTIES DEBUG_POSTFIX _debug)
    target_link_libraries(accounting_unit_test PUBLIC accounting_lib)
    set(UNIT_TEST TRUE)
endif()
