/*
 あるLevel=lに揃える場合のeffortを計算して、最小値を求める
 lまたはl+1になればいいとすると、各セルについて
 |area[n][m]-l|と|area[n][m]-(l+1)|の最小値を足す

 l<=[0,8] ※9でなくて良いのはl,l+1をチェックするから
 n<=[1,50], m<=[1,50]から、計算量の最大は
 50*50*9 なので全探索で余裕
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HouseBuilding {
public:
   int getMinimum( vector <string> area ) {
     int N=area.size();
     int M=area[0].size();
     int ans=N*M*9;

     for (int l=0; l<9; ++l) {
       int cur =0;
       for (int n=0;n<N;++n) {
	 for (int m=0;m<M;++m) {
	   cur += min(abs(l-(area[n][m]-'0')), abs((l+1)-(area[n][m]-'0')));
	 }
       }
       ans = min(ans,cur);
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
			string area[]             = {"10",
 "31"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string area[]             = {"54454",
 "61551"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string area[]             = {"989"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string area[]             = {"90"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string area[]             = {"5781252",
 "2471255",
 "0000291",
 "1212489"};
			int expected__            = 53;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
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
