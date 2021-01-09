
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "util.hpp"

// Checking primality of the number using trial division
bool isPrime(unsigned long int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n%2 == 0) return false;
	const int nSqrt = (int)std::sqrt((double)n);
    for (auto i = 3ul;  i*i < n;  i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void singlethreadPrime(const std::vector<int>& source, std::vector<int>& result1){

	for (int i = 0; i < source.size(); ++i) {
		if (isPrime(source[i]))
			result1.push_back(source[i]);
	}
				
	std::cout << "\nPrimes are: \n"; 
	for (int i = 0; i < result1.size(); i++) 
		std::cout << result1[i] << " ";
	std::cout << std::endl;
				
}

void multithreadPrime(const std::vector<int>& pVector, std::vector<int>& result2){
	// vectors to store partial results
	std::vector<int> pResult1;
	std::vector<int> pResult2;
	std::vector<int> pResult3;
	std::vector<int> pResult4;

	//split pVector in to 4 parts (4 threads -> 4 parts)
	int start = pVector.size() / 4;
	int mid1 = pVector.size()/2;
	int mid2 = pVector.size()*0.75;
	int end = pVector.size();


	//run four threads 
	std::thread t1([&]() {
		for (int i = 0; i < start; ++i) {
			if (isPrime(pVector[i]))
				pResult1.push_back(pVector[i]);
		}
	});
	std::thread t2([&]() {
		for (int i = start; i < mid1; ++i) {
			if (isPrime(pVector[i]))
				pResult2.push_back(pVector[i]);
		}
	});
	std::thread t3([&]() {
		for (int i = mid1; i < mid2; ++i) {
			if (isPrime(pVector[i]))
				pResult3.push_back(pVector[i]);
		}
	});
	std::thread t4([&]() {
		for (int i = mid2; i < end; ++i) {
			if (isPrime(pVector[i]))
				pResult4.push_back(pVector[i]);
		}
	});

	//join threads
	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
	if(t3.joinable()) t3.join();
	if(t4.joinable()) t4.join();

	//combine the results from partial results
	result2.insert(result2.end(), pResult1.begin(), pResult1.end());
	result2.insert(result2.end(), pResult2.begin(), pResult2.end());
	result2.insert(result2.end(), pResult3.begin(), pResult3.end());
	result2.insert(result2.end(), pResult4.begin(), pResult4.end());
	
	std::cout << "\nPrimes are: \n"; 
	for (int i = 0; i < result2.size(); i++) 
		std::cout << result2[i] << " ";
	std::cout << std::endl;
				
}