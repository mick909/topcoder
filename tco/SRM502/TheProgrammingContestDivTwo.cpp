/*
  requiredTimeが短いものから順に取っていけば良い
  requiredTimeの合計がTを越えたら終了
  1つ進む度に、そこまでのtimeの合計を加算する
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TheProgrammingContestDivTwo {
public:
   vector <int> find( int T, vector <int> requiredTime ) {
     vector<int> ans(2);
     ans[0] = 0; ans[1] = 0;
     int i=0;
     int t=0;
     sort(requiredTime.begin(), requiredTime.end());
     while (i<requiredTime.size()) {
       t += requiredTime[i];
       if (t > T) break;
       ++ans[0];
       ans[1] += t;
       ++i;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int T                     = 74;
			int requiredTime[]        = {47};
			int expected__[]          = {1, 47 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int T                     = 74;
			int requiredTime[]        = {4747};
			int expected__[]          = {0, 0 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int T                     = 47;
			int requiredTime[]        = {8, 5};
			int expected__[]          = {2, 18 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int T                     = 47;
			int requiredTime[]        = {12, 3, 21, 6, 4, 13};
			int expected__[]          = {5, 86 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int T                     = 58;
			int requiredTime[]        = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8};
			int expected__[]          = {10, 249 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int T                     = 100000;
			int requiredTime[]        = {100000};
			int expected__[]          = {1, 100000 };

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
