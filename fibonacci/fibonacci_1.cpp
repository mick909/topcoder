#include <iostream>
#include <cstdlib>

using namespace std;

// 計算量 O( ( (1+sqrt(5)) / 2 ) ^ (n-1) )
// n=40 -> 141422324   = 1.4e8
// fib(40) = 165580141
//  real	0m0.446s
//  user	0m0.441s
//  sys	0m0.003s
//
// n=50 -> 17393796001 = 1.7e10
// fib(50) = 20365011074
//
//  real	0m53.813s
//  user	0m53.785s
//  sys	0m0.006s
//
// n=100 -> 4.8e20
//  だいたい 4万8千年
//
// n=1000 -> 6.0e+208
//  だいたい 6*10^184 億年
//
long long fib(int n) {
  if (n == 0) return 1;
  if (n == 1) return 1;

  return fib(n-1)+fib(n-2);
}

int main(int argc, char *argv[]) {
  if (argc < 1) return 0;
  
  int n = atoi(argv[1]);
  cout << "fib(" << n << ") = " << fib(n) << endl;
}