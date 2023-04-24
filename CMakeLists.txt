cmake_minimum_required(VERSION 3.4...3.18)
set(PROJECT_NAME pybind11_beispiel)

project(${PROJECT_NAME})

add_subdirectory(src)
add_subdirectory(extern/pybind11)
pybind11_add_module(${PROJECT_NAME} src/wrapper.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    math-lib
)