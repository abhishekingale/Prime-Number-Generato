# Prime number generator using Sieve of Eratosthenes

Implementing prime numbers using Sieve of Eratosthenes algorithm.

## Usage

Using gcc
```bash
g++ -o prime primeclass.cpp
```

Using CMake and CMakeLists.txt
```bash
mkdir build
cmake ..
make
./primeclass
```
Using Build and run script
```bash
./build_and_run.sh
```

Using OpenMP and gcc
```bash
g++ -o prime primeclass.cpp -fopenmp
```
## Benchmarks


| Primes upto N | generatePrimes() (mSec)	|opti_generatePrimes() (mSec)|  generatePrimes()[OpenMP] (mSec)	| Displaying Results (mSec) |
| :---         	|     :---:      			|     :---:      			|		:---:						|   :---: 					|
| 100000   		| 1.52    					| 0.78   					|		1.165						| 21    					|
| 1000000   	| 17.86       				| 8.109    					|		5.956						| 224.6      				|
| 10000000   	| 219.9      				| 108.08   					|		93.04						| 2209.55      				|
| 100000000   	| 2654.3       				| 1139.02  					|		1195.95						| 20855.6     				|
| 1000000000   	| 30342.8     				| 13258.8    				|		14806.3						| 209686      				|


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate

