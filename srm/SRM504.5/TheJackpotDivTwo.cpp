/*
  金額ごとの人数のリストにして、
  同じ金額の人数をまとめて処理する

  必要かな？
*/
#include <cstdio>
#include <cstdlib>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TheJackpotDivTwo {
public:
   vector <int> find( vector <int> mo, int jp ) {
     map<int,int> fs;
     sort(mo.begin(), mo.end());
     for (int i=0; i<mo.size(); ++i) ++fs[mo[i]];
     vector< pair<int, int> > fsv;
     for (map<int,int>::iterator it = fs.begin(); it != fs.end(); ++it) {
       fsv.push_back(make_pair(it->first, it->second));
     }
     int i=0;
     while (jp > 0) {
       if (fsv[i].second <= jp) {
	 fsv[i].first++;
	 jp -= fsv[i].second;
	 if (i<fsv.size()-1 && fsv[i].first == fsv[i+1].first) {
	   fsv[i+1].second += fsv[i].second;
	   ++i;
	 }
       } else {
	 break;
       }
     }
     vector<int> ans;
     if (jp > 0) {
       for (int j=0; j<fsv[i].second-jp; ++j) {
	 ans.push_back(fsv[i].first);
       }
       fsv[i].first++;
       fsv[i].second = jp;
     }
     for (; i<fsv.size(); ++i) {
       for (int j=0; j<fsv[i].second; ++j) {
	 ans.push_back(fsv[i].first);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int money[]               = {1, 2, 3, 4};
			int jackpot               = 2;
			int expected__[]          = {2, 3, 3, 4 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int money[]               = {4, 7};
			int jackpot               = 1;
			int expected__[]          = {5, 7 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int money[]               = {1};
			int jackpot               = 100;
			int expected__[]          = {101 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int money[]               = {21, 85, 6, 54, 70, 100, 91, 60, 71};
			int jackpot               = 15;
			int expected__[]          = {21, 21, 54, 60, 70, 71, 85, 91, 100 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
