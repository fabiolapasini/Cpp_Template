cmake_minimum_required (VERSION 3.8)

option(BUILD_TESTS "Build tests" ON)
message(STATUS "BUILD_TESTS: ${BUILD_TESTS}")
if(BUILD_TESTS)
    enable_testing()
    list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif()

project ("Cpp_Template")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Template)
add_subdirectory(tests)

