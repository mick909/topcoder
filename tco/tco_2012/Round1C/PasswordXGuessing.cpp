/*
  騙された！
  返り値型がlong longなので総当たりで間に合わないの？
  と思わされたが、
    すべての入力について1文字が異なる文字集合を生成しても
      => 9*50*50 = 22500通り
    なので、そもそもintに収まるじゃん。。。

    生成した文字列がすべての入力にたいして1文字だけ異なるかの判定
      => 22500 * 50 * 50 = 56,250,000
    なのでギリギリに思えるけれど、すべて異なる文字列を生成して
    それがすべて条件にあてはまる、なんてことはないので（証明未）
    時間は余裕。
    (実際、SystemTestでも最大60ms程度しかかかっていない)

  教訓：
    250問題は深読みせずに全探索してしまおう・・・
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

class PasswordXGuessing {
public:
   long long howMany( vector <string> guesses ) {
     int N=guesses.size();
     int M=guesses[0].size();
     set<string> cd;

     for (int i=0; i<N; ++i) {  // 50
       for (int j=0; j<M; ++j) { // 50
	 for (int c='0'; c<='9'; ++c) { // 10
	   if (guesses[i][j] != c) {
	     string tmp=guesses[i];
	     tmp[j] = c;
	     cd.insert(tmp);
	   }
	 }
       }
     }

     set<string> ans;
     for (set<string>::iterator it = cd.begin(); it!=cd.end(); ++it) { // 50*50*9
       bool check=true;
       for (int i=0; check && i<N; ++i) { // 50
	 int dn=0;
	 for (int j=0; dn<2 && j<M; ++j) { // 50
	   if (guesses[i][j] != (*it)[j]) ++dn;
	 }
	 if (dn != 1) {
	   check = false;
	 }
       }
       if (check) ans.insert(*it);
     }
     return ans.size();
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string guesses[]          = {"58", "47"};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string guesses[]          = {"539", "540", "541"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string guesses[]          = {"12", "34", "56", "78"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string guesses[]          = {"2", "3", "5"};
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string guesses[]          = {"4747", "4747", "4747", "4747"};
			long long expected__      = 36;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string guesses[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string guesses[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string guesses[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PasswordXGuessing().howMany(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])));
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
