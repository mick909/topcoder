// Paste me into the FileEdit configuration dialog

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
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
static const ll Zp = 1000000007;

class EllysPlaylists {
public:
   int countPlaylists( vector <string> songs, int K ) {
     ll sc[2][50];
     vector<int> lk[50];
     int N=songs.size();
     vector<string> ps;
     vector<string> ns;
     for (int i=0; i<N; ++i) {
       ps.pb(songs[i].substr(songs[i].size()-3));
       ns.pb(songs[i].substr(0,3));
    }
    for (int i=0; i<N; ++i) {
       for (int j=0; j<N; ++j) {
         if (ps[i] == ns[j]) lk[i].pb(j);
        }
        sc[0][i] = 1;
    }
    
    int p=0;
    for (int i=0; i<K-1; ++i) {
      p = (p+1)%2;
      for (int j=0; j<N; ++j) {
        sc[p][j] = 0;
      }
      for (int j=0; j<N; ++j) {
        for (int k=0; k<lk[j].size(); ++k) {
          sc[p][lk[j][k]] = (sc[p][lk[j][k]] + sc[(p+1)%2][j]) % Zp;
        }
      }
     }
     int ans = 0;
     for (int i=0; i<N; ++i) {
       ans = (ans + sc[p][i]) % Zp;
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
			string songs[]            = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
  "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" };
			int K                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string songs[]            = { "aaaaaa", "aaabcd", "bcdaaa" };
			int K                     = 4;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string songs[]            = { "aaa", "aaaa", "aaaaa" };
			int K                     = 3;
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string songs[]            = { "elly", "looks", "lovely" };
			int K                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string songs[]            = { "life", "universe", "everything" };
			int K                     = 42;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string songs[]            = { "aaaaaaaaa", "aaabbbaaa", "aaacccaaa", "aaadddaaa", "aaaeeeaaa", "aaafffaaa" };
			int K                     = 12;
			int expected__            = 176782322;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string songs[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string songs[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string songs[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPlaylists().countPlaylists(vector <string>(songs, songs + (sizeof songs / sizeof songs[0])), K);
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
