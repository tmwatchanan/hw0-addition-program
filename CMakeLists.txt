cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(hw0-addition-program)

enable_language(C)
enable_language(CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    )

add_library(
    studentCode
    src/studentCode.cpp
    )

set(GOOGLETEST_ROOT test/lib/gtest-1.8.0 CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest-1.8.0 ${GOOGLETEST_SOURCES})

add_executable(
    unit_tests
    test/main.cpp
    test/example_add_1.cpp
    test/example_add_2.cpp
    )

add_dependencies(unit_tests gtest-1.8.0)

target_link_libraries(
    unit_tests
    gtest-1.8.0
    studentCode
    pthread
    )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)