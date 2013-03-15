/*
 簡単に見えたが罠にハマった。。
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FoxProgression {
public:
   int theCount( vector <int> seq ) {
     int N=seq.size();
     if (N==1) return -1;
     int dif = seq[1]-seq[0];
     int rat = seq[1]/seq[0];  // seqは1以上
     bool isa=true;
     bool isg=true;
     if (rat==0) isg=false;

     // 整数倍かチェック必要！
     if (seq[1]%seq[0]) isg=false;

     for (int i=2; i<N; ++i) {
       if (isa && seq[i]-seq[i-1] != dif) isa=false;

       // seq[i]/seq[i-1]!=ratはダメ！
       if (isg && (seq[i-1]*rat != seq[i])) isg=false;
     }
     if (isa && isg) {
       // 等差と等比が同じ結果
       if (seq[N-1]+dif == seq[N-1]*rat) return 1;
       return 2;
     }
     if (isa || isg) return 1;
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
			int seq[]                 = {1, 2, 4, 8};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {5, 3, 1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1, 1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {8, 4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int seq[]                 = {1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int seq[]                 = {4, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int seq[]                 = {1, 3, 4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
