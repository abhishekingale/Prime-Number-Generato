cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)

project(prime_parallel)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(primeParallel main.cpp util.cpp util.hpp)

target_link_libraries(primeParallel ${CMAKE_THREAD_LIBS_INIT} )

