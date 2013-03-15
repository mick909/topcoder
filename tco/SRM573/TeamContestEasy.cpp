/*
  貪欲法！
  条件を満たす(自チームの得点より大な最大値、最小値)組を数えていく
  条件を満たすペアが作れないか、
  人数(N) - できたチーム数*3 < 3 になったら、もうチームが作れないので終了
  
  jの探索範囲はいちいちN-1からにする必要はないけれど、N=48なら間に合うので。
  
  別解：
    実は、N/3の人数は、上位のチームが作れる条件にまったく寄与しない
    N/3～Nの人だけで、自チームより得点が大なペアを数えるだけでも良い
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TeamContestEasy {
public:
   int N;

   int worstRank( vector <int> st ) {
     int used[50];
     N = st.size();
     if (N <= 3) return 1;
     int ms = st[0] + st[1] + st[2] - (min(st[0],min(st[1],st[2])));
     vector<int> ss(st.begin()+3, st.end());
     sort(ss.begin(), ss.end());
     N-=3;
     for (int i=0; i<N; ++i) used[i]=0;

     int ans = 0;
     for (int i=0; i<N; ++i) {
       if (used[i]) continue;
       for (int j=N-1; j>0; --j) {
         if (used[j] || i==j) continue;
         if (ss[i]+ss[j] > ms) { ++ans; used[i]=used[j]=1; break; }
       }
       if (N-3 < (ans*3)) break;
     }
     return ans+1;
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
			int strength[]            = {5, 7, 3, 5, 7, 3, 5, 7, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int strength[]            = {5, 7, 3};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int strength[]            = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int strength[]            = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1} ;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int strength[]            = {45,72,10,42,67,51,33,21,8,51,17,72} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int strength[]            = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224, 32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int strength[]            = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589, 12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
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
