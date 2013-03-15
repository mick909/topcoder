/*
  1回目の試行で、desicionsで2票以上得た人がいない場合、
  かならず全員が1票ずつになるので終わらない => 結果は0.0

  desicionsで2票以上得た人がいる場合、残りの人がどう投票しても、
  decisions最大得票をとった人には届かない

  2回め以降は、残った人がdecisionsで得る得票数は同じままなので
  decisionsを考慮しなくてよくなる

  1回目の試行で残った人のうち1人が残るか終わらないかのいずれかとなる
  1回目の試行で残った人で1人が残る確率は全員同じである

  1回目の投票後、最大得票数の人数をvnとする
  vn == 1なら、その時点でかならず負けになるので結果は1.0

  vn > 1のとき、
  以降の試行では、(N-(vn*投票数))人がvn人に投票するので、
  (N-(vn*投票数)) % vn人が残る
    => (N- (vn*投票数)) = N % vn
  続けて行って、余りが0になったら終わらないので結果は0.0
  余りが1になったら、最初のvn人が等しい確率になるので結果は1/vn
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class MafiaGame {
public:
   double probabilityToLose( int N, vector <int> decisions ) {
     int vul[500];
     for (int i=0; i<N; ++i) vul[i]=0;
     for (int i=0; i<decisions.size(); ++i) {
       vul[decisions[i]]++;
     }
     std::sort(&(vul[0]), &(vul[0])+N);

     int max=vul[N-1];
     if (max == 1) return 0.0;

     int vn=0;
     for (int i=N-1; i>=0 && vul[i]==max; --i,++vn);
     if (vn == 1) return 1.0L;

     double ans = 1.0L/vn;
     while (vn > 1) {
       vn = N % vn;
     }
     if (vn == 0) return 0.0L;
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
			int N                     = 3;
			int decisions[]           = {1, 1, 1};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int decisions[]           = {1, 2, 3};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 20;
			int decisions[]           = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 23;
			int decisions[]           = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
			double expected__         = 0.14285714285714285;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
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
