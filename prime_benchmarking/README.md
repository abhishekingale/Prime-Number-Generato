# Benchmarking using Google Benchmark

## Installation

Follow the instructions and install Google Benchmark:

```
[Google Benchmark](https://github.com/google/benchmark)
```

## Usage

Using gcc
```bash
g++ primesoeBenchmark.cc -std=c++11 -isystem benchmark/include \
  -Lbenchmark/build/src -lbenchmark -lpthread -o mybenchmark
```

Using CMake and CMakeLists.txt
```bash
mkdir build
cmake ..
make
./primeBenchmark
```
Using Build and run script
```bash
./build_and_run.sh
```
## Benchmark Results

[Benchmarks](prime number algorithm benchmark.png)
