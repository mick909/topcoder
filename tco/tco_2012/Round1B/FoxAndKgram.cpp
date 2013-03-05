/*
  Nから順に条件を満たすかチェックしていく
  pencilの長さごとの数を最初に数えておく
  n gramを満たすかどうかは、
    長さnのpencilの数
    長さがiと(n-1)-i のpencilで作れるペアの数
  の和がn以上かどうか
  
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FoxAndKgram {
public:
   int N;
   bool isvalid(int* n, int a) {
     int r=n[a-1];
     for (int i=0; i*2+2+1<=a; ++i) {
       if ((i+1)*2+1==a) r+=n[i]/2;
       else r+= min(n[i], n[a-1-(i+1)-1]);
     }
     return (r>=a);
   }

   int maxK( vector <int> len ) {
     int n[50];
     for (int i=0; i<50; ++i) n[i]=0;
     N=len.size();
     for (int i=0; i<N; ++i) ++n[len[i]-1];
     
     for (int a=N; a>0; --a) {
       if (isvalid(n, a)) return a;
     }
     return 0;
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
			int len[]                 = {1,1,1,1,3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int len[]                 = {2,2,1,3,5,5,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int len[]                 = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int len[]                 = {2,2,2,2,2,2,2,2,2,2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int len[]                 = {1,2,3,1,2,4,2,3,1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int len[]                 = {2,3,5,7,11,13,17,19,23,29};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int len[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int len[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int len[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndKgram().maxK(vector <int>(len, len + (sizeof len / sizeof len[0])));
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
