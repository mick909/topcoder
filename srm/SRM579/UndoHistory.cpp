#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <memory>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
static const double EPS = 1e-9;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
static const ll Zp = 1000000009;

struct CmpLen {
	bool operator()(const string& l, const string& r) const {
		if (l.size() > r.size()) return true;
		return false;
	}
};

class UndoHistory {
public:
	map<char, vector<string> > UD;
   int minPresses( vector <string> lines ) {
   	int r=0;
   	int N=lines.size();
   	string bf=lines[0];
   	r = bf.size()+1;
   	char s=bf[0];
   	for(int i=1;i<=bf.size();++i) UD[s].push_back(bf.substr(0,i));
    sort(all(UD[s]), CmpLen());

   	for (int i=1; i<N; ++i) {
//   		cout << lines[i] << endl;
   		int rr;

   		{
   			char s=lines[i][0];
   			int n=UD[s].size();
   			int j=0;
   			for (j=0; j<n; ++j) {
   				if (strncmp(lines[i].c_str(), UD[s][j].c_str(), UD[s][j].size()) == 0) {
   					break;
   				}
   			}
   			if (j<n) {
//   				cout << "undo:" << UD[s][j] << ":" << (2 + lines[i].size()-UD[s][j].size()+1) << endl;
   				rr = 2 + lines[i].size()-UD[s][j].size()+1;
   			} else {
//   				cout << "undo:[]" << ":" << (2 + lines[i].size()+1) << endl;
   				rr = 2 + lines[i].size()+1;
   			}
   		}

   		if (strncmp(lines[i].c_str(), bf.c_str(), bf.size()) == 0) {
   			rr = min(rr, (int)(lines[i].size()-bf.size()+1));
   		}

   		r+=rr;
   		bf = lines[i];
   		char s=bf[0];
	   	for(int i=1;i<=bf.size();++i) UD[s].push_back(bf.substr(0,i));
	    sort(all(UD[s]), CmpLen());
   	}
   	return r;
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
			string lines[]            = {"tomorrow", "topcoder"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string lines[]            = {"a","b"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string lines[]            = {"a", "ab", "abac", "abacus" };
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string lines[]            = {"pyramid", "sphinx", "sphere", "python", "serpent"};
			int expected__            = 39;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string lines[]            = {"ba","a","a","b","ba"}
;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string lines[]            = {"absolutely", "abs", "absolute"};
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
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
