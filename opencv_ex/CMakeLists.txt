cmake_minimum_required(VERSION 3.16)
project(opencv_cpp_basic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(ch01_image_io src/ch01_image_io.cpp)
target_link_libraries(ch01_image_io PRIVATE ${OpenCV_LIBS})
