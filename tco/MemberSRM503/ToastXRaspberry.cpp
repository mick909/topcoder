/*
 割り算するだけ…
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ToastXRaspberry {
public:
   int apply( int upper_limit, int layer_count ) {
     if (upper_limit >= layer_count) return 1;

     return (layer_count+(upper_limit-1))/upper_limit;
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
			int upper_limit           = 4;
			int layer_count           = 13;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int upper_limit           = 8;
			int layer_count           = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int upper_limit           = 73;
			int layer_count           = 265;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			int upper_limit           = 5;
			int layer_count           = 11;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 4: {
			int upper_limit           = ;
			int layer_count           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int upper_limit           = ;
			int layer_count           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXRaspberry().apply(upper_limit, layer_count);
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
