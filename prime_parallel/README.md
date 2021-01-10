# Parallel(Multithread) version of prime number generator

Implementing prime numbers using trial division  method in single thread and multithread mode.

#### ```util.cpp```
It contains the functions for checking prime number, single thread implementation and multithread implementation using 4 threads.

#### ```main.cpp```
Main function calls all the function defined in util.cpp and displays the result of single thread and multithread execution. It also displays execution times of both the modes using ```std::chrono``` library functions.

## Usage

Using CMake and CMakeLists.txt

```bash
mkdir build
cmake ..
make
./primeParallel
```
Using Build and run script
```bash
./build_and_run.sh
```

## Benchmarks



| Primes upto N | SingleThread  (mSec) | MultiThread (mSec) |
| :---         |     :---:      |   :---: |
| 1001000   | 38.2    | 58.5    |
| 1000000   | 640.9       | 405.4      |
| 10000000   | 15520.7       | 7718.2      |
| 100000000   | 296066       | 133776      |

The benchmarks might change depending on your personal machine and/or processor.