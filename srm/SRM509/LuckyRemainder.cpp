/*
  SS(n+1) = SS(n) + SS(n)*10 + a[n+1]*C + a[n+1]
          = SS(n)*11 + a[n+1]*(C+1)

  SS(n+1)mod9 = SS(n)mod9 * (11mod9) + a[n+1]*((C+1)mod9)
              = SS(n)mod9 * 2 + a[n+1]*(C+1)mod9
  C = sum{ C(n,k) | k=1..n }
  C+1 = sum{ C(n,k) | k=0..n } = 2^n
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LuckyRemainder {
public:
   int getLuckyRemainder( string X ) {
     int n=X.size();
     int ans=(X[0]-'0')%9;
     int c=2;
     for (int i=1; i<n; ++i) {
       ans = (ans*2 + ((X[i]-'0')*c)) % 9;
       c= (c*2)%9;
       cout << X.substr(0,i+1) << ": " << ans << " ";
     }
     cout << endl;
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
			string X                  = "123";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string X                  = "24816";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string X                  = "8";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string X                  = "11235813213455";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
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
