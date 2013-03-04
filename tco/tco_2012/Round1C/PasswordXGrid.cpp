/*
  全フローについて、経路の加算値を一致させる場合の最小値を求める
  んだけれど、下記の解は経路の最大値をDPで計算しているだけ
  (漸化式がめんどくさい)
    経路の最大値 = 一致させる場合の最小値
  の証明はよくわからない。。。
  (SystemTest passed in practice room)
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PasswordXGrid {
public:
   int minSum( vector <string> horizontal, vector <string> vertical ) {
     int dp[2][50];
     fill(&(dp[0][0]), &(dp[0][0])+50, 0);

     int m=vertical[0].size();
     int n=horizontal.size();

     dp[1][0] = 0;
     for (int j=1; j<m; ++j) {
       dp[1][j] = dp[1][j-1] + horizontal[0][j-1]-'0';
     }

     for (int i=1; i<n; ++i) {
       dp[(i+1)%2][0] = dp[i%2][0] + vertical[i-1][0]-'0';
       for (int j=1; j<m; ++j) {
	 dp[(i+1)%2][j] = max(dp[(i+1)%2][j-1]+horizontal[i][j-1]-'0',
			  dp[i%2][j]+vertical[i-1][j]-'0');
       }
     }

     return dp[n%2][m-1];
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
			string horizontal[]       = {"1","4"};
			string vertical[]         = {"32"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string horizontal[]       = {"47", "59"};
			string vertical[]         = {"361"};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string horizontal[]       = {"36", "23", "49"};
			string vertical[]         = {"890", "176"};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string horizontal[]       = {"8888585","5888585"};
			string vertical[]         = {"58585858"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string horizontal[]       = {"7777777","7777777","7777777","7777777"};
			string vertical[]         = {"44444444","44444444","44444444"};
			int expected__            = 61;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PasswordXGrid().minSum(vector <string>(horizontal, horizontal + (sizeof horizontal / sizeof horizontal[0])), vector <string>(vertical, vertical + (sizeof vertical / sizeof vertical[0])));
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
