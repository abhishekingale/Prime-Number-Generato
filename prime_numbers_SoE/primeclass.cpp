/**********************************************************
Generation of Prime Numbers using Sieve of Eratosthenes. 
 
Author: Abhishek Ingale
**********************************************************/

#include <iostream>
#include <cstdlib> 
#include <vector>
#include <chrono>
#include <cmath>

using namespace std::chrono;

class PrimeNumber_Generator{
	private:
			// Data Members 
            char* prime;
            unsigned int N;

    public:
        virtual ~PrimeNumber_Generator()		//Definition for Destructor 
        {
            delete [] prime;
        }
		
		//Parametrized Constructor 
		PrimeNumber_Generator(unsigned last_number)
            {
                N = last_number;
				prime = new char[N+1];
            }
		// Member Function which generates prime numbers upto N using Sieve of Eratosthenes  
		void generatePrimes(){
			#pragma omp parallel for
			for (int i = 0; i <= N; i++)
				prime[i] = 1; 

			const int nSqrt = (int)std::sqrt((double)N);
			
			#pragma omp parallel for schedule(dynamic)	
			for (int i=2; i<=nSqrt; i++) 
			{ 
				if (prime[i]) 
				{ 
					for (int j=i*i; j<=N; j += i) 
						prime[j] = 0; 
				} 
			} 
			
		}
		// Member Function which displays results
		void display(){
			for (int i=2; i<=N; i++)
				if (prime[i])		
					std::cout << i << " ";
		}
};


int main() 
{ 
	// Variable Declaration and Inputs
	int nPrimes;
	std::cout<<"Enter the number up to which you want to display prime numbers: ";
	std::cin>> nPrimes;
	
	// Initial check for the provided input
	if(nPrimes<2){
		std::cout << "There are no prime numbers. Program completed!" << std::endl;
	}
	else{
		//  primes will call Parametrized Constructor 
		PrimeNumber_Generator primes(nPrimes);	
		std::cout << "Following are the prime numbers smaller than or equal to " << nPrimes << std::endl; 
			
		// Benchmarking using Chrono STL
		auto start = high_resolution_clock::now();		// Start timepoint	
			
		primes.generatePrimes();
		
		auto stop = high_resolution_clock::now();		// Stop timepoint	
		
		auto start1 = high_resolution_clock::now();
		
		// Call generatePrime()
		primes.display();
		
		auto stop1 = high_resolution_clock::now();
		
		// Calculating the time difference between start and stop
		auto duration = duration_cast<microseconds>(stop - start);
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		
		std::cout << "\n\nExecution Completed! \n"<<std::endl;
		
		// Displaying time in millisec and microsec
		std::cout << "Prime number generation took: " << duration.count() << "uS("<<duration.count()*0.001<<"mS)\n" << std::endl;
		std::cout << "Result display took: " << duration1.count() << "uS("<<duration1.count()*0.001<<"mS)\n" << std::endl;
		std::cout << "Total time:  " << duration.count() + duration1.count() << "uS("<<duration1.count()*0.001<<"mS)\n" << std::endl;
	}
	
	return 0; 
} 