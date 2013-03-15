/*
  シミュレートするだけ
  フラグを4つ用意すれば一回ループでいい
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

class ComparerInator {
public:
   int makeProgram( vector <int> A, vector <int> B, vector <int> wanted ) {
     int N=A.size();
     bool match=true;
     for (int i=0; i<N; ++i) {
       if (A[i] != wanted[i]) { match=false; break; }
     }
     if (match) return 1;
     match=true;
     for (int i=0; i<N; ++i) {
       if (B[i] != wanted[i]) { match=false; break; }
     }
     if (match) return 1;
     match=true;
     for (int i=0; i<N; ++i) {
       if (min(A[i],B[i]) != wanted[i]) { match=false; break; }
     }
     if (match) return 7;
     match=true;
     for (int i=0; i<N; ++i) {
       if (max(A[i],B[i]) != wanted[i]) { match=false; break; }
     }
     if (match) return 7;
     return -1;
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
			int A[]                   = {1};
			int B[]                   = {2};
			int wanted[]              = {2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,3};
			int B[]                   = {2,1};
			int wanted[]              = {2,3};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,3,5};
			int B[]                   = {2,1,7};
			int wanted[]              = {2,3,5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1,3,5};
			int B[]                   = {2,1,7};
			int wanted[]              = {1,3,5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {1,2,3,4,5,6,7,8,9,10,11};
			int B[]                   = {5,4,7,8,3,1,1,2,3,4,6};
			int wanted[]              = {1,2,3,4,3,1,1,2,3,4,6};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1,5,6,7,8};
			int B[]                   = {1,5,6,7,8};
			int wanted[]              = {1,5,6,7,8};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int wanted[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int wanted[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			int wanted[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ComparerInator().makeProgram(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(wanted, wanted + (sizeof wanted / sizeof wanted[0])));
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
