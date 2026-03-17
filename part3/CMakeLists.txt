# sudo apt install build-essential
# sudo apt install gdb
cmake_minimum_required(VERSION 3.10)
project(kuBig2026)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()