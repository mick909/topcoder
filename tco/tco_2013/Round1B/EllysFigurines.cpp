#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <memory>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

class EllysFigurines {
public:
  int H,W;
  int check(vector<int>& bi, int mask, int rn) {
    int cnt = 0;
    for (int h=0; h<H; ++h) {
      if ((bi[h] & mask) == 0) continue;
      ++cnt;
      h += rn-1;
    }
    return cnt;
  }

   int getMoves( vector <string> board, int R, int C ) {
     H=board.size();
     W=board[0].size();
     vector<int> bi;
     for (int h=0; h<H; ++h) {
       int rb=0;
       for (int w=0; w<W; ++w) {
	 rb <<= 1;
	 if (board[h][w] == 'X') rb |= 1;
       }
       bi.push_back(rb);
     }

     int ans = max(H,W);
     for (int cm=0; cm<(1<<W); ++cm) {
       int mask=0;
       for (int c=0; c<C; ++c) {
	 mask |= (cm >> c);
       }
       int sub = 0;
       for (int i=0; i<W; ++i) {
	 if ((cm & (1<<i))) ++sub;
       }
       sub += check(bi, ~mask, R);
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
