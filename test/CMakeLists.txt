cmake_minimum_required(VERSION 3.10)
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# Define project name
project(CPPTEST)

find_package(PkgConfig REQUIRED)
set(project_sources
main.cc
SoundexTest.cc
)
set(project_headers
)

add_executable(CPPTEST 
	${project_sources} 
    ${project_headers}
)
target_link_libraries(CPPTEST
    gtest
    gtest_main
    gmock
    pthread
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)