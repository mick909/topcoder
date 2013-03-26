#include <cstdio>
#include <cstdlib>
#include <map>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CityMap {
public:
   string getLegend( vector <string> cityMap, vector <int> POIs ) {
   	int H =cityMap.size();
   	int W = cityMap[0].size();
    int ns[26];
    fill(&(ns[0]), &(ns[0])+26, 0);
    
    for (int h=0; h<H; ++h) {
      for (int w=0; w<W; ++w) {
        if (cityMap[h][w] != '.') {
          ns[cityMap[h][w]-'A']++;
        }
    }
    }
    map<int, char> mm;
    for (int i=0; i<26; ++i) {
      if (ns[i]!=0) { mm.insert(make_pair(ns[i], i+'A')); }
    }
    string ans;
    int N=POIs.size();
    for (int i=0; i<N; ++i) {
      ans += mm[POIs[i]];
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
			string cityMap[]          = {"M....M",
 "...R.M",
 "R..R.R"};
			int POIs[]                = {3, 4};
			string expected__         = "MR";

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cityMap[]          = {"XXXXXXXZXYYY"};
			int POIs[]                = {1, 8, 3};
			string expected__         = "ZXY";

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cityMap[]          = {"...........",
 "...........",
 "...........",
 "..........T"};
			int POIs[]                = {1};
			string expected__         = "T";

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cityMap[]          = {"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
;
			int POIs[]                = {16,7,1,35,11,66} ;
			string expected__         = "GOJIRA";

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string cityMap[]          = ;
			int POIs[]                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string cityMap[]          = ;
			int POIs[]                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cityMap[]          = ;
			int POIs[]                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CityMap().getLegend(vector <string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector <int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
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
