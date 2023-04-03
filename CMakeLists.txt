cmake_minimum_required(VERSION 3.20)
project(typelists)

set(CMAKE_CXX_STANDARD 20)

add_executable(typelists main.cpp)
target_compile_options(typelists PRIVATE -fsanitize=address)
target_link_libraries(typelists PRIVATE -fsanitize=address)
target_include_directories(typelists PRIVATE include)
