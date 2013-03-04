/*
  方針：
    片方の消し方を全探索する -> 最大 2^15
    各消し方について、もう一方の消し方はXが残っている部分を
    順に消していく

    行の情報を2値化することでbitmaskで片方の消し方を演算する
    残りの行は行の値が0かで判定できる
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class EllysFigurines {
public:
  int H,W;
  int R;

  // 行で消す回数を数える
  int check(vector<int>& bi, int mask) {
    int cnt = 0;

    for (int h=0; h<H; ++h) {
      // 既に消えている行はスキップ
      if ((bi[h] & mask) == 0) continue;

      ++cnt;

      // Rの分が一度で消えるので、その次の行に移動
      // for文で+1されるので-1が要る
      h += R-1;
    }
    return cnt;
  }

   int getMoves( vector <string> board, int r, int C ) {
     H=board.size();
     W=board[0].size();
     R=r;

     // 最初にboardの内容を2値化してint配列にする
     // 15列までなのでintでok
     vector<int> bi;
     for (int h=0; h<H; ++h) {
       int rb=0;
       for (int w=0; w<W; ++w) {
	 rb <<= 1;
	 if (board[h][w] == 'X') rb |= 1;
       }
       bi.push_back(rb);
     }

     // どんなに大きくてもHかWの小さい方で消せるので
     int ans = min(H,W);

     // 列側の選択を全探索する
     // C>1の場合は重なりを考えると無駄なパターンもあるけれど
     // 判定が面倒だし所詮2^15なのでキニシナイ
     for (int cm=0; cm<(1<<W); ++cm) {

       // cm => 1の桁の列をremoveする
       // C>1の場合は連続する列が消えるのでorでマスクを重ねる
       int mask=0;
       for (int c=0; c<C; ++c) {
	 mask |= (cm >> c);
       }

       // 選択した列の数をまず数える
       int sub = 0;
       for (int i=0; i<W; ++i) {
	 if ((cm & (1<<i))) ++sub;
       }

       // 残るビットを行で消すときの回数を加える
       sub += check(bi, ~mask);

       ans = min(ans,sub);
     }
     return ans;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string board[]            = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"};
			int R                     = 2;
			int C                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"XXXXXXX"};
			int R                     = 2;
			int C                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"};
			int R                     = 1;
			int C                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
