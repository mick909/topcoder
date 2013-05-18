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

typedef complex<double> P;
struct C { P p; double r;};

bool over(const C& c1, const C& c2) {
    double d = abs(c1.p - c2.p);
    if (c1.r + c2.r <= d + EPS) {
        return false;
    }
    return true;
}

class MarblePositioning {
public:
	double dist(ll r1, ll r2) {
		return sqrt( (r1+r2)*(r1+r2) - (r1-r2)*(r1-r2) );
	}

   double totalWidth( vector <int> radius ) {
   		int N=radius.size();
   		vector<int> p(N);
   		vector<C> cs(N);
   		rep(i,0,N) p[i]=i;

   		double r=1e30;
   		do {
            cs[0].p = P(0,radius[p[0]]);
            cs[0].r = radius[p[0]];

   			for (int i=1; i<N; ++i) {
   				double d = dist(radius[p[i]], radius[p[i-1]]);
                cs[i].p = P(cs[i-1].p.real() + d,radius[p[i]]);
                cs[i].r = radius[p[i]];

   				for (int j=i-1; j>=0; --j) {
                    if (over(cs[i],cs[j])) {
                        d = dist(radius[p[i]], radius[p[j]]);
                        cs[i].p = P(cs[j].p.real() + d, radius[p[i]]);
                    }
   				}
   			}
   			r = std::min(r,cs[N-1].p.real());
   		} while (next_permutation(all(p)));
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int radius[]              = {1, 2};
			double expected__         = 2.8284271247461903;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int radius[]              = {7,7,7};
			double expected__         = 28.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int radius[]              = {10, 20, 30};
			double expected__         = 62.92528739883945;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int radius[]              = {100, 100,11,11,25};
			double expected__         = 200.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int radius[]              = {1,999950884,1};
			double expected__         = 63246.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
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
