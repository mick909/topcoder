/*
  あまりアタマの良くない解法
  playersの要素数は最大8なので、順番の総数は8!=40,320通り
  なので全探索すると、40,320*8 = 322,560回ループ
  大した回数ではないけれど、mapをいじったりしているので結構重い
  => players.size()==8のときArenaで600msくらい
     ==9だとたぶんTLE
 */
#include <cstdio>
#include <cstdlib>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef vector<int> vi;

class EllysJuice {
public:
   vector <string> getWinners( vector <string> players ) {
   	int N=players.size();
   	vi ps;
   	rep(i,0,N) ps.pb(i);

	set<string> ans;
	do {
   		map<string, double> gm;
   		rep(j,0,N) gm[players[j]]=0;
   		
   		double bt[2] = {1.0L, 1.0L};
   		for (int j=0; j<N; ++j) {
   			bt[j%2] /= 2;
   			gm[players[ps[j]]] += bt[j%2];
   		}
   		
   		vector< pair<double, string> > rs;
   		for (map<string,double>::iterator it=gm.begin(); it!=gm.end(); ++it) {
   			rs.pb(mp((*it).second, (*it).first));
   		}
   		sort(all(rs));
   		reverse(all(rs));
   		if (rs.size() > 1 && rs[0].first == rs[1].first) continue;
   		ans.insert(rs[0].second);
   	} while (next_permutation(all(ps)));
   	
   	vector<string> r;
   	for (set<string>::iterator it=ans.begin(); it!=ans.end(); ++it) r.pb(*it);
   	
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
