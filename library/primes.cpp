#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)

//static const int MAX = 200000;
static const int MAX = 10000;
static const int SQRT_MAX = sqrt(MAX);

/**
 * n以下の素数を配列pに生成する
 * 前提条件 nは大域変数MAX以下
 * retval: 生成した素数の数
 */
#if 1
int primes(int n, int *p) {
  int sieve[MAX],sqrtn=sqrt(n),cnt=0,i=0;
  rep(i,0,n)sieve[i]=1;
  for(i=2;i<=sqrtn;++i)if(sieve[i-2]){*p++=i;++cnt;for(int j=2;i*j<=n;sieve[i*j-2]=0,j++);}
  while(i<=n){if(sieve[i-2]){*p++=i;++cnt;};++i;}
  return cnt;
}
#else
// 櫛にbitsetを使う版（メモリ使用量は少ないが遅い）
int primes(int n, int *p) {
  bitset<MAX> sieve;
  int sqrtn = sqrt(n);
  int cnt=0;
  int i=0;

  sieve.set();
  for (i=2; i<=sqrtn; ++i) if (sieve[i-2]) {
    *p++ = i; ++cnt;
    for (int j=2; i*j<=n; sieve[i*j-2]=0, j++) ;
  }
  while (i<=n) { if (sieve[i-2]) { *p++ = i; ++cnt; }; ++i; }
  return cnt;
}
#endif

/**
 * 素因数分解
 * nを素因数分解する
 * param p   : 素数のリスト
 * param pcnt: pの数
 * retval f  : 素因数分解したときの、各素数(p)の係数
 * retval : 最大の素因数のp中のインデックス
 */
int prime_factorize(int n, const int *p, int pcnt, int *f) {
  int idx=0;
  for(int i=0;n>=2&&i<pcnt;++i){f[i]=0;if((n%p[i])==0){idx=i;do{f[i]++;n/=p[i];}while((n%p[i])==0);}}
  return idx;
}

/**
 * 素因数分解
 * nを素因数分解する
 * param p   : 素数のリスト
 * param pcnt: pの数
 * retval f  : 素因数分解したときの、素因数と係数のペア
 * retval : 素因数の数
 */
int prime_factorize2(int n, const int *p, int pcnt, vector<pair<int,int> >& f) {
  int idx=0;
  f.clear();
  for(int i=0;n>=2&&i<pcnt;++i){if((n%p[i])==0){f.push_back(make_pair(p[i],0));do{++(f[idx].second);n/=p[i];}while((n%p[i])==0);++idx;}}
  return idx;
}


/**
 * 素因数分解
 * nを素因数分解する
 * retval f  : 素因数分解したときの、素因数と係数のペア
 */
void prime_factorize3(int n, vector<pair<int,int> >& f) {
  f.clear();
  if (n<=3) {
    f.push_back(make_pair(n,1));
    return;
  }

  int nn=n;
  int c=0;
  if ((n%2)==0) {
    while ((n%2)==0) { n/=2; ++c; }
    f.push_back(make_pair(2,c));
  }
  
  for (int i=3; i*i<=nn && n>1; i+=2) {
    if ((n%i)==0) {
      c=0;
      while ((n%i)==0) { n/=i; ++c; }
      f.push_back(make_pair(i,c));
    }
  }

  if (n!=1) {
    f.push_back(make_pair(n,1));
  }
  return;
}

int main(int argc, char *argv[]) {
  int ps[MAX];
  int f[MAX];
  
  int lim = MAX;
  int a = 2*2*2*3*3*5;

  if (argc > 1) {
    lim = atoi(argv[1]);
  }
  if (argc > 2) {
    a = atoi(argv[2]);
  }

  int cnt = primes(lim, ps);

#if 0
  for (int i=0; i<cnt; ++i) {
    cout << setw(10) << ps[i] << flush;
  }
  cout << endl;
#endif

#if 1
  cout << "static const int prime_num = " << cnt << ";" << endl;
  cout << "static const int primes[] = {";
  for (int i=0; i<cnt; ++i) {
    if ( (i % 8) == 0 ) cout << endl << "  ";
    cout << setw(6) << ps[i] << ",";
  }
  cout << endl << "};" << endl;
#endif

#if 1
  int c = prime_factorize(a, ps, cnt, f);
  for (int i=0; i<=c; ++i) {
    if (f[i]) {
      cout << ps[i] << "^" << f[i] << " ";
    }
  }
  cout << endl;
#endif

#if 1
  vector<pair<int,int> > r;
  int c2 = prime_factorize2(a, ps, cnt, r);
  for (int i=0; i<c2; ++i) {
    cout << r[i].first << "^" << r[i].second << " ";
  }
  cout << endl;
  
  prime_factorize3(a,r);
  for (int i=0; i<r.size(); ++i) {
    cout << r[i].first << "^" << r[i].second << " ";
  }
  cout << endl;
#endif

  return 0;
}
