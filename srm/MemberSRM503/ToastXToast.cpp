/*
 単純な場合分け
 例示が大事

 一番短い時間がoverか、一番長い時間がunderはNG
 (必ず焼きすぎか、絶対焼けないことになるから)

 underかoverが1つだけだったら、その時点で1枚に決定
 (上の条件から、1つだけの場合はそれが一番端になる)

 すべてのunderがすべてのoverより短いなら、1枚で良い
 (underの最長 < overの最短)

 上記以外では、どんなパターンでも2枚で良い
   1: underの最短 + overの最長を除く全部
   2: underの最短を除く全部 + overの最長
*/
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

class ToastXToast {
public:
   int bake( vector <int> un, vector <int> ov ) {
     sort(un.begin(), un.end());
     sort(ov.begin(), ov.end());

     if (un[0] > ov[0]) return -1;
     if (un[un.size()-1] > ov[ov.size()-1]) return -1;

     if (un.size()==1) return 1;
     if (ov.size()==1) return 1;

     if (un[un.size()-1] < ov[0]) return 1;
     return 2;
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
			int undertoasted[]        = {2,4};
			int overtoasted[]         = {5,6,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int undertoasted[]        = {5};
			int overtoasted[]         = {4};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int undertoasted[]        = {1,2,3};
			int overtoasted[]         = {5,6,7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int undertoasted[]        = {1,3,5};
			int overtoasted[]         = {2,4,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
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
