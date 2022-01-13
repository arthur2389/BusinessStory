cmake_minimum_required(VERSION 3.0.0)
project(BusinessStory VERSION 1.0.0)

if (BUILD_EXEC STREQUAL UnitTestAccounting OR BUILD_EXEC STREQUAL UnitTestTimeContainers)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(src/accounting)
include_directories(src/time_containers)
add_subdirectory(src/accounting)
add_subdirectory(src/time_containers)


if (BUILD_EXEC STREQUAL UnitTestAccounting)
    message("Running cmake for accounting unit test")
    add_executable(UnitTestAccounting UnitTestAccounting.cpp)
    set_target_properties(UnitTestAccounting PROPERTIES DEBUG_POSTFIX _debug)
    target_link_libraries(UnitTestAccounting PUBLIC accounting_lib)
endif()

if (BUILD_EXEC STREQUAL UnitTestTimeContainers)
    message("Running cmake for time containers unit test")
    add_executable(UnitTestTimeContainers UnitTestTimeContainers.cpp)
    set_target_properties(UnitTestTimeContainers PROPERTIES DEBUG_POSTFIX _debug)
    target_link_libraries(UnitTestTimeContainers PUBLIC accounting_lib)
    target_link_libraries(UnitTestTimeContainers PUBLIC time_containers_lib)
endif()
