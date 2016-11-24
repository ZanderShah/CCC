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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
typedef unordered_map<int, int> umii;

const double EPS = 1e-6;

int T, N, x, y, D, onTarget;
pii h[3005], o;
pdd b;
unordered_map<double, int> A, B;

inline double dist(pdd a, pdd b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double angle(pdd a, pdd b) {
	pdd c = mp(b.x - a.x, b.y - a.y);
	return round(atan2(c.y, c.x) / EPS) * EPS;
}

inline bool equals(pdd a, pdd b) {
	return fabs(a.x - b.x) <= EPS && fabs(a.y - b.y) <= EPS;
}

int fly() {
	A.clear();
	int ret = 0;

	for (int i = 1; i <= N; i++)
		if (dist(o, h[i]) <= D + EPS)
			A[angle(o, h[i])]++;

	// Try the angle for every target
	for (int i = 1; i <= N; i++) {
		B.clear();
		onTarget = 0;
		b = mp(D * cos(atan2(h[i].y - o.y, h[i].x - o.x)) + o.x,
				D * sin(atan2(h[i].y - o.y, h[i].x - o.x)) + o.y);

		// Account for target on top of return
		for (int j = 1; j <= N; j++)
			if (equals(b, h[j]))
				onTarget++;

		// See how many targets it would hit
		for (int j = 1; j <= N; j++) {
			if (!equals(b, h[j])) {
				B[angle(b, h[j])]++;
				ret = max(ret, A[angle(o, h[i])] * (B[angle(b, h[j])] + onTarget));
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &x, &y, &D, &N);
		o = mp(x, y);
		for (int i = 1; i <= N; i++)
			scanf("%d %d", &h[i].x, &h[i].y);
		printf("Case #%d: %d\n", t, fly());
	}
}
