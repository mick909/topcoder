/*
  漸化式
    n : 最小値を求めるwork数
    p : 最小値を求めるworkの開始位置
    ans(n,p) = work[p] ... n==1
               min {
                    work[p] + split + ans(n-1,p+1)
                    split + max(ans(i, p), ans(n-i,p+i)), i=1..n-1
                   }   ... n>1
    ans(n,p)をメモ化する(50x50)
    
    work[]は降順にソートして時間のかかるworkが先になるようにする
    (これでよい理由は証明未)

  地道にn=5くらいまでパターンを列挙すると、漸化式のパターンが見えた
  
  N=1 : w

  N=2 : w s w
        s w
          w

  N=3 : w s w s w
        w s s w
              w
        s w
          w s w
        s w
          s w
            w

  N=4 : w s w s w s w
        w s w s s w
                  w
        s w
          s w
            s w
              w
        s w s w
          s w
            w
        s s w
            w
          s w
            w
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FoxAndDoraemon {
public:
   vector<int> wc;
   int sc;
   int DP[50][50];
   
   int dp(int w, int p) {
     if (w==1) return wc[p];
     if (DP[w-1][p] > 0) return DP[w-1][p];
     
     int ret = wc[p] + dp(w-1, p+1);
     for (int i=1; i<w; ++i) {
       ret = min(ret, max(dp(i, p),dp(w-i, p+i)));
     }
     return DP[w-1][p] = ret+sc;
   }

   int minTime( vector <int> workCost, int splitCost ) {
     wc = workCost;
     sc = splitCost;
     sort(wc.begin(), wc.end());
     reverse(wc.begin(), wc.end());
     for (int i=0; i<50; ++i) for(int j=0; j<50; ++j) DP[i][j]=-1;

     return dp(wc.size(), 0);
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
			int workCost[]            = {1,2};
			int splitCost             = 1000;
			int expected__            = 1002;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int workCost[]            = {3,6,9,12};
			int splitCost             = 1000;
			int expected__            = 2012;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int workCost[]            = {1000,100,10,1};
			int splitCost             = 1;
			int expected__            = 1001;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int workCost[]            = {1712,1911,1703,1610,1697,1612};
			int splitCost             = 100;
			int expected__            = 2012;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int workCost[]            = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			int splitCost             = 3000;
			int expected__            = 15000;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int workCost[]            = {58};
			int splitCost             = 3600;
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndDoraemon().minTime(vector <int>(workCost, workCost + (sizeof workCost / sizeof workCost[0])), splitCost);
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
