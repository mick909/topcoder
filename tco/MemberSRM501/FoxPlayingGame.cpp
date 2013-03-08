/*
 単純な条件判断だが、nB==0やparamB==0,nB!=0の場合は
 特別な条件として見ることが必要。

 「乗算」「0がある」「負数がある」の条件での大小判断は
 注意が必要
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FoxPlayingGame {
public:
   double theMax( int nA, int nB, int paramA, int paramB ) {
     if (paramA == 0 || nA == 0) return 0.0;

     // nB==0の場合は先に判定した方が良い
     if (nB == 0) return (double)(paramA * nA)/1000.0L;

     // paramBが0の場合の条件を見落とす
     if (paramB == 0 && paramA >0) {
       return (double)(paramA * nA)/1000.0;
     }
     if (paramB == 0 && paramA < 0) {
       return 0.0;
     }

     // ここから先は、正負と1/n倍の場合を考慮するだけ
     double ans = (paramA * nA)/1000.0;
     if (paramA > 0) { 
       if (paramB > 1000) {
	 for (int i=0; i<nB; ++i) {
	   ans *= ((double)paramB/1000.0);
	 }
       } else if (paramB < -1000) {
	 for (int i=0; i<nB-(nB%2); ++i) {
	   ans *= ((double)paramB/1000.0);
	 }
       }
     } else {
       if (paramB > 0 && paramB < 1000) {
	 for (int i=0; i<nB; ++i) {
	   ans *= ((double)paramB/1000.0);
	 }
       } else if (paramB<0 && paramB >= -1000) {
	 ans *= ((double)paramB/1000.0);
       } else if (paramB < -1000) {
	 for (int i=0; i<nB-((nB+1)%2); ++i) {
	   ans *= ((double)paramB/1000.0);
	 }
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int nA                    = 5;
			int nB                    = 4;
			int paramA                = 3000;
			int paramB                = 2000;
			double expected__         = 240.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int nA                    = 3;
			int nB                    = 3;
			int paramA                = 2000;
			int paramB                = 100;
			double expected__         = 6.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int nA                    = 4;
			int nB                    = 3;
			int paramA                = -2000;
			int paramB                = 2000;
			double expected__         = -8.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int nA                    = 5;
			int nB                    = 5;
			int paramA                = 2000;
			int paramB                = -2000;
			double expected__         = 160.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int nA                    = 50;
			int nB                    = 50;
			int paramA                = 10000;
			int paramB                = 2000;
			double expected__         = 5.62949953421312E17;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int nA                    = 41;
			int nB                    = 34;
			int paramA                = 9876;
			int paramB                = -1234;
			double expected__         = 515323.9982341775;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
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
