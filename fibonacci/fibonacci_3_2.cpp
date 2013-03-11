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
// fib(1000000) = 499151567
//
//   real	0m0.018s
//  user	0m0.011s
//  sys	0m0.005s
//
// fib(1000000000) % 1000000009 = 13
//
//  real	0m5.017s
//  user	0m5.011s
//  sys	0m0.003s

long long fib(int n) {
  long long prev = 1;
  long long f = 1;
    
  for (int i=2; i<=n; ++i) {
    long long n=(f+prev) % 1000000009;
    prev = f;
    f = n;
  }

  return f;
}

int main(int argc, char *argv[]) {
  if (argc < 1) return 0;
  
  int n = atoi(argv[1]);
  cout << "fib(" << n << ") % 1000000009 = " << fib(n) << endl;
}