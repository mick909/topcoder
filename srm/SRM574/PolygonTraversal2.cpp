/*
 DFSで全探索 -> 繋がっていない点を辿って交差し続けて始点に辿りつけたらansを+1する
 交差判定は、線分の重なり判定が使える
 (a,b) と (c,d)が交差しているとは、線分にして(a,b)と(c,d)が重なっていて含まれていないと同値
 ※ a<b, c<dに注意
 
 終了条件が微妙
 N個たどった時に、始点に交差して帰れれば辿りつけた、と判定した
 */
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PolygonTraversal2 {
public:
   bool isinter(int a, int b, int c, int d) {
//   	cout << "(" << a << "," << b << "),(" << c << "," << d << ") ";
     if (a > b) swap(a,b);
     if (c > d) swap(c,d);
//   	cout << "(" << a << "," << b << "),(" << c << "," << d << ") ";
     int s1 = (a-c)*(b-d);
     int s2 = (a-d)*(b-c);
//     cout << s1 << "," << s2 << endl;
     if (s1>0 && s2<0) return true;
     return false;
    }
 
 	int ans;
 	
 	void dfs(int v, int e, int n, vector<int> ed) {
 		if (n == NN) {
// 			cout << "last";
 			for (int j=0; j<ed.size(); ++j) {
 				if (ed[j]>=0) {
 					if (isinter(v, e, j, ed[j])) {
// 						cout << " - ok" << endl;
 						++ans;
 						return;
 					}
 				}
 			}
// 			cout << " - fail" << endl;
 			return;
 		}

		for (int i=0; i<ed.size(); ++i) {
 			if (i==v) continue;
 			if (ed[i] >= 0) continue;
 			// まだ誰とも繋がっていない点について、交差する線分があるか調べる
 			// 交差する線分があったら、dfsする
 			for (int j=0; j<ed.size(); ++j) {
 				if (ed[j]>=0) {
 					if (isinter(v, i, j, ed[j])) {
 						ed[v] = i;
 						dfs(i, e, n+1, ed);
 						ed[v] = -1;
 						
 						// ここでループを抜けないとまずい
 						break;
 					}
 				}
 			}
 		}
  	}

	int NN; 		
   int count( int N, vector <int> points ) {
	NN = N;
     vector<int> vs;
     for (int i=0; i<N; ++i) vs.push_back(-1);
     
     int fn=points.size();
     for (int i=1; i<fn; ++i) vs[points[i-1]-1] = points[i]-1;
     
     int s = points[fn-1]-1;
     int e = points[0]-1;
     
     ans = 0;
     
     dfs(s,e,fn,vs);
     
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
			int N                     = 5;
			int points[]              = {1, 3, 5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 6;
			int points[]              = {1, 4, 2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int points[]              = {2, 4, 7};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 7;
			int points[]              = {1, 2, 3, 4, 6, 5};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 11;
			int points[]              = {1, 5, 10};
			int expected__            = 1412;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PolygonTraversal2().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
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
