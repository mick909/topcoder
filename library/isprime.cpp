#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <bitset>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

bool isprime(long long pc) {
  if (pc == 1) return false;
  if (pc == 2) return true;
  if ((pc % 2) == 0) return false;
  
  long long lim = (long long)sqrt(pc);
  for (long long i=3; i<=lim; ++i) {
    if ((pc%i)==0) return false;
  }
  return true;
}


int main(int argc, char *argv[]) {
  long long pc = 1000000;

  if (argc > 1) {
    pc = atoll(argv[1]);
  }
  
  if (isprime(pc)) cout << pc << " is prime" << endl;
  else cout << pc << " is not prime" << endl;
  
  return 0;
}