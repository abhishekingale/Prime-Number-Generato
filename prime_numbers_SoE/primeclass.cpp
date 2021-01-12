/**********************************************************
Generation of Prime Numbers using Sieve of Eratosthenes. 
 
Author: Abhishek Ingale
**********************************************************/

#include <iostream>
#include <cstdlib> 
#include <vector>
#include <chrono>
#include <cmath>
#include <limits>

using namespace std::chrono;

class PrimeNumber_Generator{
	private:
			// Data Members 
            char* prime;
			char* optimized_prime;
            unsigned int N,memorySize;

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
				
				memorySize = (N-1)/2;
				optimized_prime = new char[memorySize+1];				
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
		
		void opti_generatePrimes(){
			#pragma omp parallel for	
			for (int i = 0; i <= memorySize; i++)
				optimized_prime[i] = 1;
			
			const int nSqrt = (int)std::sqrt((double)N);
			
			// find all odd non-primes
			#pragma omp parallel for schedule(dynamic)	
			for (int i = 3; i<=nSqrt; i += 2)
			{
				if (optimized_prime[i/2])
				{
					for (int j = i*i; j <= N; j += 2*i)
						optimized_prime[j/2] = 0;
				}
			}
		}	
			
		
		// Member Function which displays results
		void display(){
			for (int i=2; i<=N; i++)
				if (prime[i])		
					std::cout << i << " ";
		}
		
		void display_optiPrimes(){
			for (int i=2; i<=memorySize; i++)
				if (optimized_prime[i])		
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
	while(1){
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<< "Input Error!" << std::endl;
			std::cout<<"Please enter any positive integer again: "<<std::endl;
			std::cin>> nPrimes;
		}
		if(!std::cin.fail())
		break;
	}
	
	if(nPrimes<2){
		std::cout << "There are no prime numbers. Program completed!" << std::endl;
	}
	else{
		//  primes will call Parametrized Constructor 
		PrimeNumber_Generator primes(nPrimes);	
		std::cout << "Following are the prime numbers smaller than or equal to " << nPrimes << std::endl; 
			
		// Benchmarking using Chrono STL
		auto start = high_resolution_clock::now();		// Start timepoint		
		primes.generatePrimes();						// Call generatePrime()
		auto stop = high_resolution_clock::now();		// Stop timepoint	
		
		auto start1 = high_resolution_clock::now();
		primes.display();								// Call display()
		auto stop1 = high_resolution_clock::now();
		
		auto start2 = high_resolution_clock::now();		
		primes.opti_generatePrimes();					// Call opti_generatePrime()
		auto stop2 = high_resolution_clock::now();			
		
		// Calculating the time difference between start and stop
		auto duration = duration_cast<microseconds>(stop - start);
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		auto duration2 = duration_cast<microseconds>(stop2 - start2);
		
		std::cout << "\n\nExecution Completed! \n"<<std::endl;
		
		// Displaying time in millisec and microsec
		std::cout << "Prime number generation took: " << duration.count() << "uS("<<duration.count()*0.001<<"mS)\n" << std::endl;
		std::cout << "Optimized Prime number generation took: " << duration2.count() << "uS("<<duration2.count()*0.001<<"mS)\n" << std::endl;
		std::cout << "Result display took: " << duration1.count() << "uS("<<duration1.count()*0.001<<"mS)\n" << std::endl;
		std::cout << "Total time:  " << duration.count() + duration1.count() << "uS("<<duration1.count()*0.001<<"mS)\n" << std::endl;
	}
	
	return 0; 
} 