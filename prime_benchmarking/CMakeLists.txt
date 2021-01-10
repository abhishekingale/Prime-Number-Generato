cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)

project(prime_benchmarking)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(benchmark REQUIRED)

find_package(Threads REQUIRED)

add_executable(primeBenchmark primesoeBenchmark.cc)

target_link_libraries(primeBenchmark ${CMAKE_THREAD_LIBS_INIT} )

target_link_libraries(primeBenchmark benchmark::benchmark)

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_LINK_FLAGS}")
