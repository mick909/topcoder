/*
 すべての貼り方を調べようとすると、50!/(50-6)!=1.1*10^11となりTLE

 ステッカーの種類で場合分け可能
   6色以上ある場合 => すべての面に別の色を貼れる
   2色以下の場合  => どうやっても貼れない

   5色の場合 => どれかが2枚あれば貼れる(1,1,1,1,2の組み合わせ)
   4色の場合 => 2枚ある色が2色あれば貼れる(1,1,2,2の組み合わせ)
   3色の場合 => すべて2枚ずつあれば貼れる(2,2,2の組み合わせ)
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class CubeStickers {
public:
   string isPossible( vector <string> stk ) {
     int n=stk.size();
     map<string, int> stm;
     for (int i=0; i<n; ++i) {
       ++stm[stk[i]];
     }
     int cn=stm.size();
     if (cn >= 6) return "YES";
     if (cn < 3) return "NO";

     vector<int> vn;
     for (map<string,int>::iterator it = stm.begin(); it!=stm.end(); ++it) {
       vn.push_back(it->second);
     }
     sort(vn.begin(), vn.end());
     if (cn == 5 && vn[4]>=2) return "YES";
     if (cn == 4 && vn[2]>=2) return "YES";
     if (cn == 3 && vn[0]>=2) return "YES";
     return "NO";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string sticker[]          = {"cyan","magenta","yellow","purple","black","white","purple"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string sticker[]          = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string sticker[]          = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string sticker[]          = {"purple","orange","orange","purple","black","orange","purple"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string sticker[]          = {"white","gray","green","blue","yellow","red","target","admin"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
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
