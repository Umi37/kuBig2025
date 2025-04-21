cmake_minimum_required(VERSION 3.10)
project(STL)



file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()