/*
 先頭から走査
 連続した番号のカードを組していく
 のこった組の数が答え
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

class SRMCards {
public:
   int maxTurns( vector <int> cards ) {
     sort(cards.begin(), cards.end());
     int ans=cards.size();
     for (int i=1; i<cards.size(); ++i) {
       if (cards[i-1] == cards[i]-1) {
	 --ans;
	 ++i;
       }
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
			int cards[]               = {498, 499};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cards[]               = {491, 492, 495, 497, 498, 499};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cards[]               = {100, 200, 300, 400};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cards[]               = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int cards[]               = {118, 321, 322, 119, 120, 320};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int cards[]               = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int cards[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int cards[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int cards[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
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
