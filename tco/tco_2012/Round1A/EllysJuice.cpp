/*
  勝利条件は、
   playersが一人だけ
  or
   2回以上飲める
  だけ。
  最初に2回飲む=0.5+0.5=1を得ると、
  以後は他の人が有限回どれだけ飲んでも決して1.0に達しない

  最初にplayers.size()==1の場合を場合分けして、
  あとは2回以上出てくる名前を集めてsortして返せばよい
 */
#include <cstdio>
#include <cstdlib>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EllysJuice {
public:
   vector <string> getWinners( vector <string> players ) {
    int N=players.size();
    if (N == 1) return players;
    
    map<string, int> msi;
    vector<string> ans;
    for (int i=0; i<N; ++i) {
      string& nm = players[i];
      if (msi.find(nm) == msi.end()) msi[nm] = 0;
      else if (msi[nm] == 1) ans.push_back(nm);
      ++msi[nm];
     }
     
     sort(ans.begin(), ans.end());
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string players[]          = { "elly", "kriss", "stancho", "elly", "stancho" };
			string expected__[]       = {"elly", "stancho" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string players[]          = {"torb", "elly", "stancho", "kriss"};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string players[]          = {"elly", "elly", "elly", "elly", "elly"};
			string expected__[]       = {"elly" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string players[]          = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
			string expected__[]       = {"ariadne", "elly", "stancho" };

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string players[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysJuice().getWinners(vector <string>(players, players + (sizeof players / sizeof players[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
