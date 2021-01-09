
#include <vector>
#include <iostream>
#include <chrono>
#include "util.hpp"

using namespace std::chrono;

int main(){
	
	// Variable Declaration and Inputs
	unsigned long int nPrimes;
	std::cout<<"Enter the number up to which you want to display prime numbers: ";
	std::cin>> nPrimes;
	
	std::vector<int> primes;
	std::vector<int> result1, result2;
	
	for (int i = 2; i <= nPrimes; i++) 
        primes.push_back(i);
	
	// Benchmarking using Chrono STL
	auto start = high_resolution_clock::now();
	singlethreadPrime(primes, result1);			// Calling single thread function and passing vectors
	auto stop = high_resolution_clock::now();
			
	auto start1 = high_resolution_clock::now();
	multithreadPrime(primes, result2);			// Calling multi thread function and passing vectors
	auto stop1 = high_resolution_clock::now();
	
	// Calculating the time difference between start and stop
	auto duration = duration_cast<microseconds>(stop - start);
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	
	// Displaying time in millisec and microsec
	std::cout << std::endl;
	std::cout << "SingleThread took: " << duration.count() << "uS("<<duration.count()*0.001<<"mS)\n" << std::endl;
	std::cout << "MultiThread (4 threads) took: " << duration1.count() << "uS("<<duration1.count()*0.001<<"mS)\n" << std::endl;	
	return 0;
}

