/*
 BとBの逆順が含まれている位置を調べて、
 その前後の文字数から計算できる
 
 先頭だけで不安だったので、見つかるすべてのBとBの逆順について
 調べてみたけれど、じつは先頭だけでも良かった
 */
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class TheNumberGameDiv2 {
public:
   int minimumMoves( int A, int B ) {
     stringstream ssA, ssB;
     ssA << A;
     string As = ssA.str();
     ssB << B;
     string Bs = ssB.str();
     string RBs = Bs;
     reverse(RBs.begin(), RBs.end());
     
     int pn = As.find(Bs,0);
     int rn = As.find(RBs,0);
     if (pn == string::npos && rn == string::npos) return -1;
     
     int ans1=999;
     int ans2=999;

//	while (pn != string::npos) {     
	if (pn != string::npos) {     
	   	int aa = As.size() - pn - Bs.size();
	   	if (pn > 0) { aa += pn+2; }
	   	ans1 = min(ans1,aa);
	   	pn = As.find(Bs, pn+1);
	}

//    while (rn != string::npos) {
    if (rn != string::npos) {
     	int aa = As.size() - rn - RBs.size();
     	if (rn > 0) { aa += rn; }
     	++aa;
     	ans2 = min(ans2,aa);
     	rn = As.find(RBs,rn+1);
     }
     	
     return min(ans1,ans2);
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
			int A                     = 25;
			int B                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 123123123;
			int B                     = 123123;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 334;
			int B                     = 12;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 218181918;
			int B                     = 9181;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 9798147;
			int B                     = 79817;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
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
