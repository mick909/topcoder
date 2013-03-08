/*
  難しいことを考えるとかえってハマるなあ

  方針：当たりの枚数を数える

  ・当たり番号から重複を消す

  ・"123", "4123"の場合、"123"の枚数を数えれば
    "4123"も数えられるので、"4123"を当たり番号から消す
　・"123", "4123", "5123", "12123", "14123"などの場合も
   "123"の枚数だけを数えれば良い

    => 短い方から順に、自分を含むものを探して消していけば良い

  ・残った当たり番号の枚数は単純に計算できる
    "123456789"が当たりの場合は、1枚 = 100,000,000/100,000,000
    "12345678"が当たりの場合は、10枚 = 100,000,000/ 10,000,000
    "1234567"が当たりの場合は、100枚 = 100,000,000/  1,000,000
    "123456"が当たりの場合は、1000枚 = 100,000,000/    100,000
    "12345"が当たりの場合は、10000枚 = 100,000,000/     10,000
    "1234"が当たりの場合は、100000枚 = 100,000,000/      1,000
    "123"が当たりの場合は、1000000枚 = 100,000,000/        100
    "12"が当たりの場合は、10000000枚 = 100,000,000/         10
    "1"が当たりの場合は、100000000枚 = 100,000,000/          1
  当たり枚数の合計/1,000,000,000が答え
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct ord {
  bool operator()(const string& l, const string& r) const {
    if (l.size()<r.size()) return true;
    if (l.size()>r.size()) return false;
    if (l<r) return true;
    return false;
  }
};

class TheLotteryBothDivs {
public:
   double find( vector <string> gs ) {
     // ソートする
     // 短いものから並ぶように比較オブジェクトordを定義
     sort(gs.begin(),gs.end(),ord());

     // 重複を消す("X"でマークする)
     string prev="";
     for (int i=0; i<gs.size(); ++i) {
       if (gs[i] == prev) gs[i]="X";
       else prev = gs[i];
     }

     // より長いものでsuffixとしてすでにあるものを含むものを消す
     for (int i=0; i<gs.size(); ++i) {
       string& v = gs[i];
       if (v == "X") continue;
       for (int j=i+1; j<gs.size(); ++j) {
	 if (gs[j] == "X") continue;
	 if (gs[j].substr( gs[j].size()-v.size() ) == v) gs[j]="X";
       }
     }

     // 枚数数え用10のべき乗を先に計算
     ll f[9];
     f[0] = 1;
     for (int i=1; i<9; ++i) {
       f[i] = f[i-1]*10;
     }

     // 当たり数値の長さ毎に、当たり枚数を数える
     ll count[9] = {0};
     for (int i=0; i<gs.size(); ++i) {
       if (gs[i] == "X") continue;
       int d=gs[i].size();
       count[d-1] += 100000000LL / f[d-1];
     }

     // 当たり枚数を合計
     ll get=0;
     for (int i=0; i<9; ++i) {
       get += count[i];
     }

     // 1,000,000,000で割って終わり
     return ((double)get)/1000000000LL;
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
			string goodSuffixes[]     = {"4"};
			double expected__         = 0.1;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string goodSuffixes[]     = {"4", "7"};
			double expected__         = 0.2;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string goodSuffixes[]     = {"47", "47"};
			double expected__         = 0.01;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string goodSuffixes[]     = {"47", "58", "4747", "502"};
			double expected__         = 0.021;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string goodSuffixes[]     = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
			double expected__         = 0.201100101L;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
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
