# cmake_minimum_required(VERSION <specify CMake version here>)
project(console-quiz)

set(CMAKE_CXX_STANDARD 14)

add_executable(console-quiz main.cpp)

#COPY FILES TO BUILD FOLDER
file(COPY quiz_list.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY quiz_01.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY quiz_02.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY quiz_03.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY quiz_04.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY quiz_05.txt DESTINATION ${CMAKE_BINARY_DIR})