/*
  mergeする順番は n!/2通りとなってしまうのですべて試してみることはできない

  「どのcity(のname)が残ることができるか？」だけがわかればいいので、
  各cityについてそのnameが残るために最善の順でマージして、
  残れるかどうかを判定すれば良い

  各cityについて、popがpop[i]以下のcityはnameを残したままmerge可能で、
  結果としてsum(pop[k] | k=0残れる..i)のcityとなる。
  あとは、pop[i]以上のcityについて小さい順にnameを残したまま
  mergeできるかチェックしていって、最後までmergeできるかをチェックする

  最初のcityの数から、残れなかったcityの数を引いたものが答えとなる
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class SlimeXSlimesCity {
public:
   int merge( vector <int> pop ) {
     int n=pop.size();
     sort(pop.begin(), pop.end());
     int ans=n; // 最小値が残らないとは限らない（全部同じpopの場合）
     for (int i=0; i<n; ++i) {
       ll s=pop[i]; // popは 10^9 まであるので
       for (int j=0; j<i; ++j) s+=pop[j];
       for (int j=i+1; j<n; ++j) {
	 if (s < pop[j]) { --ans; break; }
	 s += pop[j]; // 何で忘れるかな
       }
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
			int population[]          = {2, 3, 4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int population[]          = {1, 2, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int population[]          = {8,2,3,8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int population[]          = {1000000000, 999999999, 999999998, 999999997};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int population[]          = {1,1,1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int population[]          = {1, 2, 4, 6, 14, 16, 20};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
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
