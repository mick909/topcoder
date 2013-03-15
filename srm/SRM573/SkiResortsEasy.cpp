/*
 順に下げていくだけ
 */
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class SkiResortsEasy {
public:
   int minCost( vector <int> altitude ) {
     int ans = 0;
     int N=altitude.size();
     for (int i=1; i<N; ++i) {
       int d = max(0, altitude[i]-altitude[i-1]);
       ans += d;
       altitude[i] -= d;
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
			int altitude[]            = {30, 20, 20, 10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int altitude[]            = {5, 7, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int altitude[]            = {6, 8, 5, 4, 7, 4, 2, 3, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int altitude[]            = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88};
			int expected__            = 2284;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int altitude[]            = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745};
			int expected__            = 6393;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int altitude[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int altitude[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int altitude[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SkiResortsEasy().minCost(vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
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
