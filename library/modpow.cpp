#include <iostream>
using namespace std;

typedef long long ll;

/*****************************************************
 * a^bを計算する
 *
 * binary methodにより、lg(b)回のループで計算
 *****************************************************/
ll pow(int a, int b) {
  int s=0,k=0;
  while(b){s<<=1;s|=b&1;b>>=1;++k;}
  ll ans=1;
  while(k-->0){ans*=ans;if(s&1)ans*=a;s>>=1;}
  return ans;
}

/*****************************************************
 * (a^b)mod pを計算する
 *
 * binary methodにより、lg(b)回のループで計算
 *****************************************************/
int powmod(int a, int b, int p) {
  int s=0,k=0;
  while(b){s<<=1;s|=b&1;b>>=1;++k;}
  ll ans=1;
  while(k-->0){ans=(ans*ans)%p;if(s&1)ans=(ans*a)%p;s>>=1;}
  return ans;
}

/*****************************************************
 * (a/b)mod pを計算する
 *****************************************************/
int divmod(int a, int b, int p) {
  int q=p,x=0,y=1,r,t;
  while(r=b%q){t=y;y=x;x=t-(b/q)*x;b=q;q=r;}
  b = (x+p)%p;
  return ((ll)a*b)%p;
}

/*****************************************************
 * aのpを法とする逆元を求める
 * (pは素数であり、aはpの倍数では無いこと)
 *
 * (a * invmod(a,p)) mod p = 1
 * (a/b) mod p = (a * invmod(b,p)) mod p となる
 *
 * 計算量はlg(a)
 *****************************************************/
int invmod(int a, int p) {
  int q=p,x=0,y=1,r,t;
  while(r=a%q){t=y;y=x;x=t-(a/q)*x;a=q;q=r;}
  return (x+p)%p;
}

/*****************************************************
 * nCrを計算する
 *
 * r回のループで計算
 * 桁あふれに注意
 *****************************************************/
ll cmb(int n, int r) {
  ll ans=1;
  for(int i=0;i<r;++i)ans=(ans*(n-i))/(i+1);
  return ans;
}

/*****************************************************
 * nCr mod pを計算する
 * divmodが必要
 *
 * r log(p)回のループで計算
 *****************************************************/
int cmbmod(int n, int r, int p) {
  ll ans=1;
  for(int i=0;i<r;++i)ans=divmod((ans*(n-i))%p,i+1,p);
  return ans;
}

/*****************************************************
 * 最大公約数
 *****************************************************/
int gcd(int a, int b) {
  int r;
  while(r=a%b){a=b;b=r;}
  return b;
}
/*
  return (b==0?a:gcd(b,a%b));
*/

/*****************************************************
 * 最小公倍数
 *****************************************************/
int lcm(int a, int b) {
  return a/gcd(a,b)*b;
}

/*****************************************************
 * 拡張ユークリッド互除法
 *
 * a, bに対して、ax + by = gcd(a,b)となるx,yを求める
 * (普通のユークリッド互除法のほうが速い)
 *****************************************************/
void xgcd(int a, int b, int&x, int&y) {
  x=1;y=0;
  int x1=0,y1=1,q,r2,x2,y2;
  while(b>0){q=a/b;r2=a%b;x2=x-q*x1;y2=y-q*y1;a=b;b=r2;x=x1;x1=x2;y=y1;y1=y2;}
}
/*
  if (b==0) {x=1; y=0;}
  else { xgcd(b, a%b, y, x); y -= a/b*x; }
*/

/*****************************************************/

#if 0
/**
 * aのpを法とする逆元を求める
 * (pは素数であり、aはpの倍数では無いこと)
 *
 * (a * invmod(a,p)) mod p = 1
 * (a/b) mod p = (a * invmod(b,p)) mod p となる
 *
 * 計算量はlg(a)
 */
int invmod(int a, int p) {
  return (a==1?1:(1LL-(ll)p*invmod(p%a,a))/a+p);
}
#endif

/*****************************************************/

#define P 1000000009

int main(int argc, char *argv[]) {
/*
  ll p521 = pow(5,21);
  int p521_1 = p521 % P;
  int p521_2 = invmod(p521_1, P);
  cout << "powmod: 5^21 mod P= " << p521_1 << " == " << powmod(5, 21, P) << endl;
  cout << "invmod: " << p521 << " mod P = " << p521_1 << "*" << p521_2 << "->" << (((ll)p521_1 * (ll)p521_2)%P) << endl;

  cout << "divmod: 5^21 mod P / 5^21 mod P = " << divmod(p521_1, p521_1, P) << endl;
*/
  ll c83 = cmb(50,14);
//  int c83p = cmbmod(50,25,P);
  cout << "cmbmod: 50C14 = " << c83 /* << " mod P->" << (c83%P) << "==" << c83p*/ << endl;
/*
  int x,y;
  xgcd(37632, 3780, x, y);
  cout << "gcd: " << x << "," << y << "  gcd=" << (37632*x+3780*y) << "=" << gcd(37632,3780) << endl;
*/
  return 0;
}
