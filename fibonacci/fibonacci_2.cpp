#include <iostream>
#include <cstdlib>

using namespace std;

// 計算量 O( n )
// fib(40) % 1000000009 = 165580141
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s
//
// fib(50) % 1000000009 = 365010894
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s
//
// fib(100) % 1000000009 = 486534406
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s
//
// fib(1000000) -> Segmentation fault

long long DP[101];

long long fib(int n) {
  if (DP[n] > 0) return DP[n];

  if (n == 0) return (DP[n] = 1);
  if (n == 1) return (DP[n] = 1);

  return (DP[n] = (fib(n-1)+fib(n-2)) % 1000000009);
}

int main(int argc, char *argv[]) {
  if (argc < 1) return 0;
  
  fill(&(DP[0]), &(DP[0])+101, -1);

  int n = atoi(argv[1]);
  cout << "fib(" << n << ") % 1000000009 = " << fib(n) << endl;
}