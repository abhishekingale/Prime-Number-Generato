/**** Function definitions for prime number generator ****/

// function to check primality of the number
bool isPrime(unsigned long int);

// function to run the prime vectors using single-thread
void singlethreadPrime(const std::vector<int>&, std::vector<int>&);

// function to run the prime vectors using multi-thread (4 threads)
void multithreadPrime(const std::vector<int>&, std::vector<int>&);