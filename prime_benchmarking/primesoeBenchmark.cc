#include <benchmark/benchmark.h>
#include<iostream>
#include<cmath>
#include<vector>

std::vector<int> prime; 
	
void primeGenerator(int n) 
{	
	if(n<2){
		std::cout << "There are no prime numbers. Program completed!" << std::endl;
	}
	else{
		prime.assign(n,1);

	const int nSqrt = (int)std::sqrt((double)n);
	
	for (int i=2; i<=nSqrt; i++) 
	{ 
		if (prime[i]) 
		{ 
			for (int j=i*i; j<=n; j += i) 
				prime[j] = 0; 
		} 
	} 
	}
} 

static void BM_Prime(benchmark::State& state) {
  for (auto _ : state){
   primeGenerator(state.range(0)) ;
  }
  state.SetComplexityN(state.range(0));
}
// Register the function as a benchmark
BENCHMARK(BM_Prime)->RangeMultiplier(2)->Range(8192, 1<<29);

BENCHMARK_MAIN();