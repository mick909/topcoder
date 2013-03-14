#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void make_knight(int a, int b, int n, int m, vvi& bd) {
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      int k=0;
      if (i-a >= 0 && j-b >= 0) ++k;
      if (i-a >= 0 && j+b <  n) ++k;
      if (i-b >= 0 && j-a >= 0) ++k;
      if (i-b >= 0 && j+a <  n) ++k;
      if (i+a <  m && j-b >= 0) ++k;
      if (i+a <  m && j+b <  n) ++k;
      if (i+b <  m && j-a >= 0) ++k;
      if (i+b <  m && j+a <  n) ++k;
      bd[i][j] = k;
    }
  }
}

void make_knight2(int a, int b, int n, int m, vvi& bd) {
  int mvx[] = {1, 1, -1, -1};
  int mvy[] = {1, -1, 1, -1};
  int dx[8], dy[8];
  
  for (int i=0; i<4; ++i) {dx[i]=a*mvx[i]; dy[i]=b*mvy[i];}
  for (int i=0; i<4; ++i) {dx[i+4]=b*mvx[i]; dy[i+4]=a*mvy[i];}
  int cx[6], cy[6];
  
  cx[0] = 0; cy[0] = 0;
  cx[1] = a; cy[1] = a;
  cx[2] = b; cy[2] = b;
  cx[3] = n-b; cy[3] = m-b;
  cx[4] = n-a; cy[4] = m-a;
  cx[5] = n; cy[5] = m;
  sort(&(cx[0]), &(cx[0])+6);
  sort(&(cy[0]), &(cy[0])+6);
  int kc[5][5][5];
  
  for (int i=0; i<6; ++i) {
    for (int j=0; j<6; ++j) {
      int mm=0;
      int x1 = cx[j];   int y1=cy[i];
      int x2 = cx[j+1]; int y2=cy[i+1];
      kc[i][j][0] = x1; kc[i][j][1] = y1; kc[i][j][2] = x2; kc[i][j][3] = y2; kc[i][j][4] = 0;
      if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
      for (int k=0; k<8; ++k) {
        int xx = x1 + dx[k];
        int yy = y1 + dy[k];
        if (0 <= xx && xx < n && 0 <= yy && yy < m) ++mm;
      }
      kc[i][j][4] = n;
      
      for (int ii=y1; ii<y2; ++ii) {
        for (int jj=x1; jj<x2; ++jj) {
          bd[ii][jj] = mm;
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int a=2;
  int b=6;
  int n=15;
  int m=15;

  if (argc > 1) a = atoi(argv[1]);
  if (argc > 2) b = atoi(argv[2]);
  if (argc > 3) n = atoi(argv[3]);
  if (argc > 4) m = atoi(argv[4]);

  vvi board;
  for (int i=0; i<m; ++i) board.push_back(vi(n));

  make_knight(a, b, n, m, board);
  cout << "(" << a << "," << b << ") " << n << "x" << m << endl;
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  vvi board2;
  for (int i=0; i<m; ++i) board2.push_back(vi(n));

  make_knight2(a, b, n, m, board2);
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      cout << board2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

