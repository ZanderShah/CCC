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

struct State {
	int i, d, r;
	bool operator< (const State &s) const {
		if (s.r == r) {
			return s.d < d;
		}
		return s.r < r;
	}
};

int t, N, T, cost[105][105], risk[105][105], dist[105][255];
bool vis[105][255];
priority_queue<State> pq;

// Minimum total risk to get from 1 to N with dist < T

void solve() {
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &risk[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T; j++) {
			dist[i][j] = 1 << 30;
		}
	}
	dist[1][0] = 0;

	memset(vis, 0, sizeof vis);

	pq.push(State{1, 0, 0});

	while (!pq.empty()) {
		int i = pq.top().i, d = pq.top().d;
		pq.pop();

		vis[i][d] = 1;

		for (int j = 1; j <= N; j++) {
			int dd = d + cost[i][j];
			if (dd <= T && !vis[j][dd] && dist[i][d] + risk[i][j] <= dist[j][dd]) {
				dist[j][dd] = dist[i][d] + risk[i][j];
				pq.push(State{j, dd, dist[j][dd]});
			}
		}
	}
	pii ans = mp(1 << 30, 0);
	for (int i = 0; i <= T; i++) {
		if (dist[N][i] < ans.x) {
			ans = mp(dist[N][i], i);
		}
	}
	if (ans.x == 1 << 30) {
		printf("-1\n");
	} else {
		printf("%d %d\n", ans.x, ans.y);
	}
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		solve();
	}
}
