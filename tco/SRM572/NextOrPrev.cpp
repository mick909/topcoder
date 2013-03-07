/*
  上昇するグループと下降するグループにわける
  NG条件を判定する
    NG条件 = ある文字の移動範囲が、他の文字の移動範囲に完全に含まれる --(1)
          | ある文字の移動範囲が、移動しない文字を含んでいる    --(2)
              -> 含む側の移動中に必ず他の文字と同じ文字になってしまう
                 startとgoalに同じ文字は含まれないので、
                 同じ文字が出てきてしまったらgoalにたどり着けない
          | 上昇するグループと下降するグループの移動範囲が重なる --(3)

    上昇するグループ、下降するグループのグループ内では、
    移動範囲が重なっても良い

    ・それぞれのグループにおいて以下のような移動があったら ret(-1)
       g1     　g1      s1      s1
       | g2     |       | s2    |
       | |      | s=g   | |     | s=g
       | s2     |       | g2    |
       s1       s1      g1      g1

    ・上昇するグループと下降するグループとで重なるものがあったら ret(-1)
       g1
       |  s2
       |  |
       s1 |
          g2

    ・このパターンは移動可能(どちらもs2から先に移動すればぶつからない)
          g2         s1
       g1 |      s2  |
       |  s2     |   |
       |         |   g1
       s1        g2
 */
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

class NextOrPrev {
public:
  int N;
   int getMinimum( int nextCost, int prevCost, string start, string goal ) {
     N=start.size();

     // uds[0]:下降するグループ, uds[1]:上昇するグループ
     vpii uds[2];
     // ss:移動しない文字セット
     vi   ss;

     for (int i=0; i<N; ++i) {
       if (start[i] > goal[i]) uds[0].pb(mp(goal[i],start[i]));
       if (start[i] < goal[i]) uds[1].pb(mp(start[i],goal[i]));
       if (start[i]==goal[i]) ss.pb(start[i]);
     }
     sort(all(uds[0]));
     sort(all(uds[1]));

     // それぞれのグループで、(1)条件を判定
     for (int k=0; k<2; ++k) {
       // iの範囲を[1,size())とするのがポイント
       // [0,size()-1)はNG => size()がunsignedなので、-1しても0より小にならない
       // [1,size())にしておくと、vectorのサイズが0,1の場合でもループにはいらずに
       // 正しく動作する
       for (int i=1; i<uds[k].size(); ++i) {
         if (uds[k][i-1].second > uds[k][i].second) return -1;
       }
     }

     int c[2];
     c[0] = prevCost; c[1] = nextCost;
     int ans = 0;
     // それぞれのグループで(2)条件を判定
     // ついでに移動コストの合計を計算
     // 範囲は[0,size())で、vectorが空でも大丈夫
     for (int k=0; k<2; ++k) {
       for (int i=0; i<uds[k].size(); ++i) {
	 ans += (uds[k][i].second-uds[k][i].first)*c[k];
	 for (int j=0; j<ss.size(); ++j) {
	   if (uds[k][i].first < ss[j] && ss[j] < uds[k][i].second) return -1;
	 }
       }
     }
     /*
     // どちらかのグループが空なら、この時点でOK
     // 実は要らない
     if (uds[0].size() == 0 || uds[1].size() == 0) {
       return ans;
     }
     */

     // cp: 上昇グループと下降グループを走査するイテレータ
     int cp[2] = {0,0};
     // dx: どちらのグループの下端が下側か（最初は上昇グループが下と仮定）
     int dx=1;

     // どちらかのグループを走査し終わったら完了
     while (cp[0]<uds[0].size() && cp[1]<uds[1].size()) {
       // 下端が下側になるグループをチェック
       if (uds[dx^1][cp[dx^1]].first < uds[dx][cp[dx]].first) {dx^=1;}

       // 下側の上端が、上側の下端より上だったら、重なってしまっている
       if (uds[dx][cp[dx]].second > uds[dx^1][cp[dx^1]].first) return -1;

       // 下端の側を一つ進める
       ++cp[dx];
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
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "bc";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "cb";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int nextCost              = 1;
			int prevCost              = 1;
			string start              = "srm";
			string goal               = "srm";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "acb";
			string goal               = "bdc";
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "zyxw";
			string goal               = "vuts";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int nextCost              = 563;
			int prevCost              = 440;
			string start              = "ptrbgcnlaizo";
			string goal               = "rtscedkiahul";
			int expected__            = 10295;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int nextCost              = 126;
			int prevCost              = 311;
			string start              = "yovlkwpjgsna";
			string goal               = "zpwnkytjisob";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
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
