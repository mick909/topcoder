/*
 解その２

 最高到達位置は、firstからp回+d分upしてから、(n-2-p)回-d分downした
 last直前の位置lが、|last-l|<=d となった地点 -(1)
 ただし、last>lの場合は、(last-l)のupを一回増やせる -(2)
   0 <= p <n-1, n=2かつfirst>lastの時は(2)の補正ができない

 pは0から数えてもn-2から数えても結果は同じ
   lastの直前の位置lは2d単位で移動するから

 最後の条件(n=2かつ first>lastは補正できない)が面倒
 (見落とすとWA)

 n==2の場合はmax(first,last)なので先に弾いた方が楽
 すると、かならず補正( max(0, last-l)の加算 )ができる

 探索範囲を[a=0, b=n-1)として二分探索
 b=n-1はpの条件外だけれど、計算上必ず範囲外になるので
 開区間の開始位置として利用できる
 二分探索では条件外の値でも判定さえできれば利用してよい
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TheArray {
public:
   int find( int n, int d, int first, int last ) {
     if (n==2) return max(first,last);

     int a = 0;
     int b = n-1;

     while (a+1<b) {
       int p = (a+b)/2;
       int m = first + p * d;
       int l = m - (n-2-p) * d;
       if (l > last+d) b=p; else a=p;
     }

     int ans = first + a*d;
     int las = ans - (n-2-a) * d;
     ans += max(0, last-las);
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
			int n                     = 3;
			int d                     = 5;
			int first                 = 2;
			int last                  = 4;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int d                     = 100;
			int first                 = 999;
			int last                  = 100;
			int expected__            = 999;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1000000;
			int d                     = 0;
			int first                 = 474;
			int last                  = 474;
			int expected__            = 474;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 97;
			int d                     = 53;
			int first                 = -92;
			int last                  = 441;
			int expected__            = 2717;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 99;
			int d                     = 3;
			int first                 = -743;
			int last                  = -619;
			int expected__            = -535;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
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
