/*
 これだけで良い・・・
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

class NextOrPrev {
public:
   int getMinimum( int nextCost, int prevCost, string start, string goal ) {
     int N=start.size();
     int ans = 0;
     for (int i=0; i<N; ++i) {
       for (int j=i+1; j<N; ++j) {
	 // 二つの移動が衝突しないことは、この条件だけで良い
         if (start[i]<start[j] && goal[i]>goal[j]) return -1;
         if (start[i]>start[j] && goal[i]<goal[j]) return -1;
       }
       if (start[i]<goal[i]) ans += (goal[i]-start[i])*nextCost;
       if (start[i]>goal[i]) ans += (start[i]-goal[i])*prevCost;
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
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "bc";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "cb";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int nextCost              = 1;
			int prevCost              = 1;
			string start              = "srm";
			string goal               = "srm";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "acb";
			string goal               = "bdc";
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "zyxw";
			string goal               = "vuts";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int nextCost              = 563;
			int prevCost              = 440;
			string start              = "ptrbgcnlaizo";
			string goal               = "rtscedkiahul";
			int expected__            = 10295;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int nextCost              = 126;
			int prevCost              = 311;
			string start              = "yovlkwpjgsna";
			string goal               = "zpwnkytjisob";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
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
