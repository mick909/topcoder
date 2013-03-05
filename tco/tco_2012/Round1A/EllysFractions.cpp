/*
  気がつけば簡単だけど気がつくかどうか…
  
  AとBは互いに素なので、n!を素因数分解して、
  その素因数をAとBに振り分ける場合の数を、n <= [1..N]で加算する
  
  AとBに振り分ける場合の数は、2^(素因数の数)
    => 1000110 とビットで置いて、1の位置をA, 0の位置をBと考えられる
  A<Bの条件から1/2するが、2^(素因数の数) * 1/2 = 2^(素因数の数-1)
  
  N<=250でN以下の素数の数は53個なので、53bit=long longで計算
  
  素因数分解の係数は関係ないので、
  n!を素因数分解した素因数の数は、n以下の素数の数を数えるだけで良い。
 */
#include <cstdio>
#include <cstdlib>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

static const int prime_num = 53;
static const int primes[] = {
       2,     3,     5,     7,    11,    13,    17,    19,
      23,    29,    31,    37,    41,    43,    47,    53,
      59,    61,    67,    71,    73,    79,    83,    89,
      97,   101,   103,   107,   109,   113,   127,   131,
     137,   139,   149,   151,   157,   163,   167,   173,
     179,   181,   191,   193,   197,   199,   211,   223,
     227,   229,   233,   239,   241,
};

class EllysFractions {
public:
   long long getCount( int N ) {
     // 素数判定用の集合を作っておく
     set<int> ps;
     for (int i=0; i<53; ++i) {
       ps.insert(primes[i]);
     }

     // これまでに現れた素数の数
     int pn=0; 
     
     // N=1の場合は0と分かっているので、N=2から回す
     ll ans = 0;
     for (int i=2; i<=N; ++i) {
       if (ps.find(i) != ps.end()) ++pn;
       // (1LL)を忘れると、64ビットを越えちゃうのでWA
       ans += (1LL)<<(pn-1);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int N                     = 1;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100;
			long long expected__      = 177431885;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysFractions().getCount(N);
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
