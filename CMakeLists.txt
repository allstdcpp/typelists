cmake_minimum_required(VERSION 3.20)
project(typelists)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
                                                     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

add_subdirectory(tests)
