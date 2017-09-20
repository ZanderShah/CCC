#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <unordered_map>
#include <map>
#include <bitset>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

const double EPS = 1e-6;

int N, w[4005], v, mv;
pii p[4005];
vector<pair<float, int> > tp, pp;
double a;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &p[i].x, &p[i].y, &w[i]);
	}

	for (int p0 = 0; p0 < N; p0++) {
		// Recenter all points around p[p0] and sort by angle
		for (int p1 = 0; p1 < N; p1++) {
			if (p0 == p1) {
				continue;
			}
			a = atan2(p[p1].y - p[p0].y, p[p1].x - p[p0].x);
			tp.pb(mp(a, w[p1]));
			tp.pb(mp(a + 2 * M_PI, w[p1]));
		}
		sort(tp.begin(), tp.end());
		// Deal with colinear points by treating them as one point
		for (int i = 0; i < tp.size(); i++) {
			v = tp[i].y;
			while (i + 1 < tp.size() && fabs(tp[i].x - tp[i + 1].x) <= EPS) {
				v += tp[++i].y;
			}
			pp.pb(mp(tp[i].x, v));
		}

		v = max(0, w[p0]);

		for (int i = 0, j = 0; pp[i].x < M_PI; i++) {
			while (pp[j].x - pp[i].x <= M_PI) {
				v += pp[j].y;
				j++;
			}
			mv = max(mv, v);
			v -= pp[i].y;
		}

		tp.clear();
		pp.clear();
	}

	printf("%d\n", mv);
}
