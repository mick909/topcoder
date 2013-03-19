/*
 sum + x = pro * xから、sum / (pro-1) = x
 つまり、sumをpro-1で割りきれれば"Yes"

 x>=1なので、sum > (pro-1)に気をつけてproを掛け算する
 sum > (pro-1)
 sum < (pro'-1)のときpro'は9*10^18に収まるか？
  => seqが50個までという制限から、収まる

 seqに0を含む場合を忘れがち（罠）
 最初から条件を満たす場合はExampleで落ちるので気がつく
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

class PerfectSequences {
public:
   string fixIt( vector <int> seq ) {
     int N=seq.size();
     if (N==1) return "Yes";

     int zn=0;
     ll sum=0;
     for (int i=0; i<N; ++i) {
       if (seq[i] == 0) ++zn;
       sum += seq[i];
     }
     if (zn == N-1) return "Yes";
     if (zn > 1) return "No";

     bool chk=true;
     ll ts = sum;
     for (int i=0; i<N; ++i) {
       if (seq[i] == 0 || ts < seq[i] || (ts % seq[i])!=0) { chk=false; break; }
       ts /= seq[i];
     }
     if (chk && ts == 1) return "No";

     for (int i=0; i<N; ++i) {
       ts = sum-seq[i];
       ll pro=1;
       for (int j=0; j<N; ++j) {
	 if (i==j) continue;
	 pro *= seq[j];
	 if (pro > (ts+1)) { pro=-1; break; }
	 if (pro == 0) { pro=-1; break; }
       }
       if (pro > 1 && (ts % (pro-1)) == 0) return "Yes";
     }
     return "No";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int seq[]                 = {1,3,4};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {1,2,3};
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1,4,2,4,2,4};
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {1000000,1,1,1,1,2};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int seq[]                 = {8};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int seq[]                 = {2,0,2};
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PerfectSequences().fixIt(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
