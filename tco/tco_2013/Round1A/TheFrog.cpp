#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;

class TheFrog {
public:
   double getMinimum( int D, vector <int> L, vector <int> R ) {
     vpii pits;
     int N=L.size();
     for (int i=0; i<N; ++i) pits.push_back(make_pair(L[i],R[i]));
     sort(pits.begin(),pits.end());

     double ans = (double)(D);

     // 各pit i<=[0,N-1]のR側について、そのn分の一でjump可能か探索する
     for (int i=0; i<N; ++i) {
       int pr = pits[i].second;

       // jumpの最小値 = divの最大値を求めるので、MAXから-1しながら調べる
       // divの最大値から最小値(=1)に向かって探索する
       // divの最大値はpr。
       // なぜなら、pr/(pr+1) < 1となり、pitの幅は >=1 なので、
       // 一つでもpitがあると絶対に飛び越えられない
       //
       // 1から順に飛び越えられなくなるまで、はNG
       // なぜなら、div=2がだめでもdiv=3はOKということがありえる
       int div=pr+1;

       // jumpできるものが出てくるまでdivを減らす
       bool ok;
       do {
	 --div;
	 ok=true;

	 // (pr/div)のjumpで、全pit j<=[0,N-1]をjumpできるか調べる
	 // (pr/div)をjumpしながらではなく、以下の計算をしている
	 //
	 // 0                                pr
	 // 0   p1     p2     p3     p4    p(div)
	 //               lk-----rk
	 // lkの左側で一番大きいp(k)を探す (p(k) <= lk, p(k+1)> lk)
	 // p(k+1)がrkより小さい場合はpitに落ちる => if p(k+1) < rk then fall down
	 // 
	 // p(k) = floor(lk/p1)*p1, p1=pr/div
	 // p(k+1) = floor(lk/p1)*p1 + p1
	 // if ((floor(lk/(pr/div)) + 1) * (pr/div) < rk ... ?
	 //
	 // このまま計算すると、誤差の罠にはまる
	 // 整数だけで計算できるよう、不等式を変形する
	 // (floor(lk/(pr/div)) + 1) * pr < rk * div  (div>1)
	 // (floor(lk*div/pr) * pr + pr < rk * div
	 //
	 // floor(lk*div/pr) * pr = lk*div - ((lk*div) mod pr)
	 //   lk*div = a*pr + b (0<=b<=pr-1)とすると、
	 //   floor(lk*div/pr) = a
	 //   floor(lk*div/pr)*pr = a*pr = lk*div - b = lk*div - ((lk*div) mod pr)
	 //
	 // よって、lk*div - ((lk*div)mod pr) + pr < rk * div が条件式（整数のみ）
	 for (int j=0; ok && j<N; ++j) {
	   int lp = pits[j].first * div;
	   if ((lp-(lp % pr) + pr) < pits[j].second * div) {
	     ok = false;
	   }
	 }

	 // 全pitをjumpできたら、pr/divを解の候補とする
	 if (ok) {
	   ans = min(ans, (double)(pr) / div);
	   break;
	 }
       } while (div > 1);

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
			int D                     = 16;
			int L[]                   = {2};
			int R[]                   = {7};
			double expected__         = 7.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int D                     = 25;
			int L[]                   = {11, 3};
			int R[]                   = {21, 7};
			double expected__         = 10.5;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int D                     = 100;
			int L[]                   = {0};
			int R[]                   = {100};
			double expected__         = 100.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int D                     = 100;
			int L[]                   = {0, 50};
			int R[]                   = {50, 100};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int D                     = 30000;
			int L[]                   = {17, 25281, 5775, 2825, 14040};
			int R[]                   = {55, 26000, 5791, 3150, 14092};
			double expected__         = 787.8787878787879;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
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
