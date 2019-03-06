cmake_minimum_required(VERSION 3.0)

set(NAME mathematics_cpp_test)

add_executable(${NAME} main.cpp mathematics_cpp/library_test.h)

target_include_directories(${NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${NAME} mathematics_cpp)