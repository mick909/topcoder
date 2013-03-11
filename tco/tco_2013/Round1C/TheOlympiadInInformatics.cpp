/*
 Johnがp点のとき、最大で何人がより高い得点を得るか？という問題に変形する
 人数が最大なので、p+1点を何人分取れるかを計算すれば良い
 sum(sums[i]/(p+1))が、p+1点を取れる人数
 Johnは0点から1,000,000,000点まで取れる
 
 Johnがp点の時p+1点を取れる人数は、pの増加にともない減少"または同じ"
 なので、k人を越えるちょうどそのpを探索する
 
 1,000,000,000 * 47なので単純なループではTLEの恐れ
 pに比例して人数が減少なので、二分探索できる
 
 (a,b]の区間探索。aは、a+1点を取れる人数がkを越えるところ。

 sum(sums[i]/(p+1))はintをあふれるので注意！
  => 最大値は、1,000,000,000 * 47 = 47*10^9 > 2.15*10^9 > 2^31
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class TheOlympiadInInformatics {
public:
   int find( vector <int> sums, int k ) {
    int N=sums.size();
    ll a = -1;
    ll b = 1000000000;

    while (a+1<b) {
      ll m = (a+b)/2;
      ll tot=0;
      for (int i=0; i<N; ++i) tot += sums[i]/(m+1);
      if (tot > k) a=m; else b=m;
    }
    
    return b;
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
			int sums[]                = {4, 7, 0, 5};
			int k                     = 0;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sums[]                = {4, 7};
			int k                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sums[]                = {999999999};
			int k                     = 1000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sums[]                = {95, 23, 87, 23, 82, 78, 59, 44, 12};
			int k                     = 70;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
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
