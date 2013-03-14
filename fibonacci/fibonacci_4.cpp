#include <iostream>
#include <cstdlib>

using namespace std;

// 計算量 O( log(n) )
// fib(40) % 1000000009 = 165580141
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s
//
// fib(50) % 1000000009 = 365010894
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
// log(1000000) = 13.8
// fib(1000000) % 1000000009 = 499151567
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s
//
// log(1000000000) = 20.7
// fib(1000000000) % 1000000009 = 13
//
//  real	0m0.005s
//  user	0m0.002s
//  sys	0m0.002s

#define P 1000000009

long long fib(int n) {
  long long Q[4] = {1, 0, 0, 1};

  int s=0,k=0;
  while (n) {
  	s <<= 1;
  	s |= n&1;
  	n >>= 1;
  	++k;
  }

  while (k-->0) {
  	long long a,b,c,d;
  	a = Q[0]; b = Q[1]; c = Q[2]; d = Q[3];
  	Q[0] = ((a*a)%P + (b*c)%P) % P;
  	Q[1] = ((a*b)%P + (b*d)%P) % P;
  	Q[2] = ((c*a)%P + (d*c)%P) % P;
  	Q[3] = ((c*b)%P + (d*d)%P) % P;
    if (s&1) {
      a = Q[0]; b = Q[1]; c = Q[2]; d = Q[3];
      Q[0] = (a+c)%P; Q[1] = (b+d)%P; Q[2] = a; Q[3] = b;
    }
    s >>= 1;
  }
  return Q[0];
}

int main(int argc, char *argv[]) {
  if (argc < 1) return 0;
  
  int n = atoi(argv[1]);
  cout << "fib(" << n << ") % 1000000009 = " << fib(n) << endl;
}