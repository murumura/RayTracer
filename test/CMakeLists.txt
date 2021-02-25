cmake_minimum_required(VERSION 3.10)
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Define project name
project(raytracer_test)

find_package(PkgConfig REQUIRED)
set(project_sources
main.cc
Test_common.cc
)
set(project_headers
../../include/vec.hh 
../../include/common.hh
../../include/constmath.hh
)

add_executable(raytracer_test 
	${project_sources} 
    ${project_headers}
)
target_include_directories(raytracer_test
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/../include
)
target_link_libraries(raytracer_test
    gtest
    gtest_main
    gmock
    pthread
)
