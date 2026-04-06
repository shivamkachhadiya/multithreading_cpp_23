cmake_minimum_required(VERSION 4.2)
project(multithreading_cpp_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(multithreading_cpp_23
        firstFile.cpp
        demoanThread.cpp
        thread_ownership.cpp
        number_of_threads.cpp
        race_condition.cpp
        thread_id.cpp
        thread_test.cpp)
