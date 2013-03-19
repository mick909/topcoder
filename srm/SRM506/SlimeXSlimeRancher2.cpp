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

class SlimeXSlimeRancher2 {
public:
   int train( vector <int> as ) {
     int N=as.size();
     sort(as.begin(), as.end());
     int mx=as[N-1];
     int ans=0;
     for (int i=0; i<N-1; ++i) {
       ans += mx-as[i];
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
			int attributes[]          = {1,2,3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int attributes[]          = {5,5};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int attributes[]          = {900,500,100};
			int expected__            = 1200;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int attributes[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int attributes[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int attributes[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimeRancher2().train(vector <int>(attributes, attributes + (sizeof attributes / sizeof attributes[0])));
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
