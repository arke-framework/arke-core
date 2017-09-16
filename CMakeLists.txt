cmake_minimum_required(VERSION 3.8)
project(arke)

set(CMAKE_CXX_STANDARD 17)

# Enable test
enable_testing()

message("-- Compiler familly ${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # Add coverage
    SET(COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -stdlib=libc++")
    SET(COVERAGE_LINK_FLAGS    "--coverage  -stdlib=libc++ -lc++abi")
else()
    # Add coverage
    SET(COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    SET(COVERAGE_LINK_FLAGS    "-lgcov")
endif()

# Add coverage
add_definitions(${COVERAGE_COMPILE_FLAGS})

# Add library
add_library(
        arke

        Sources/json/JSONEncoder.hxx Sources/json/JSONDecoder.hxx

        Sources/designation/Designation.cxx Sources/designation/Designation.hxx
        Sources/designation/DesignationBuilder.cxx Sources/designation/DesignationBuilder.hxx
        Sources/designation/DesignationEncoder.cxx Sources/designation/DesignationEncoder.hxx
        Sources/designation/DesignationDecoder.cxx Sources/designation/DesignationDecoder.hxx

        Sources/dependency/Dependency.cxx Sources/dependency/Dependency.hxx
        Sources/dependency/DependencyBuilder.cxx Sources/dependency/DependencyBuilder.hxx
        Sources/dependency/DependencyEncoder.cxx Sources/dependency/DependencyEncoder.hxx
        Sources/dependency/DependencyDecoder.cxx Sources/dependency/DependencyDecoder.hxx
)
target_include_directories(arke

        PRIVATE
            Sources
            Dependencies
)

# Add test executable
add_executable(
        arke_test

        Tests/catch.hpp
        Tests/main.cxx
        Tests/Designation_test.cxx
        Tests/Dependency_test.cxx)
target_include_directories(
        arke_test

        PRIVATE
            Dependencies
            Sources
)
target_link_libraries(
        arke_test
        arke
        ${COVERAGE_LINK_FLAGS}
)


# Register test
add_test(arke_test arke_test)
