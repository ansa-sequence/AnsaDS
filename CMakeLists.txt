cmake_minimum_required(VERSION 3.20)
project(AnsaDS CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(AlgoTests)