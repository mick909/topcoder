#include <iostream>
#include <vector>
#include <cstdlib>

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

  return 0;
}

