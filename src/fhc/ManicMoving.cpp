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
#include <unordered_set>
#include <map>
#include <bitset>
#include <stdio.h>

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
typedef unordered_map<int, int> umii;

int T, N, M, K, g[105][105], d[105][105], dp[5005][105][3];
pii job[5005];
bool vis[105][105];
priority_queue<pii> pq;

void dijkstra(int x) {
	d[x][x] = 0;
	pq.push(mp(0, x));
	while (!pq.empty()) {
		int i = pq.top().y;
		pq.pop();
		vis[x][i] = 1;
		for (int j = 1; j <= N; j++) {
			if (!vis[x][j] && g[i][j]
			    && (d[x][j] == -1 || d[x][j] > d[x][i] + g[i][j])) {
				d[x][j] = d[x][i] + g[i][j];
				pq.push(mp(-d[x][j], j));
			}
		}
	}
}

// [# delivered][location][amount in truck]
int wtf(int i, int cur, int load) {
	if (i + load == K) {
		if (load == 0) {
			return 0;
		} else if (load == 1) {
			return d[cur][job[i + 1].y];
		} else {
			return d[cur][job[i + 1].y] + d[job[i + 1].y][job[i + 2].y];
		}
	}

	if (dp[i][cur][load] != -1) {
		return dp[i][cur][load];
	}

	int ret = 1e8;
	if (load == 0) {
		// Have to pick up a package
		if (i + 1 <= K) {
			ret = min(ret, wtf(i, job[i + 1].x, 1) + d[cur][job[i + 1].x]);
		}
	} else if (load == 1) {
		// Drop off
		if (i + 1 <= K) {
			ret = min(ret, wtf(i + 1, job[i + 1].y, 0) + d[cur][job[i + 1].y]);
		}
		// Pick up
		if (i + 2 <= K) {
			ret = min(ret, wtf(i, job[i + 2].x, 2) + d[cur][job[i + 2].x]);
		}
	} else if (load == 2) {
		// Have to drop off a package
		if (i + 1 <= K) {
			ret = min(ret, wtf(i + 1, job[i + 1].y, 1) + d[cur][job[i + 1].y]);
		}
	}

	return dp[i][cur][load] = ret;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; r++) {
		memset(g, 0, sizeof g);
		memset(d, -1, sizeof d);
		memset(vis, 0, sizeof vis);
		memset(dp, -1, sizeof dp);

		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0, a, b, x; i < M; i++) {
			scanf("%d %d %d", &a, &b, &x);
			g[a][b] = g[a][b] ? min(g[a][b], x) : x;
			g[b][a] = g[a][b];
		}
		// All pairs shortest path
		for (int i = 1; i <= N; i++) {
			dijkstra(i);
		}
		// Check if all jobs are on the same graph
		bool blocked = 0;
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &job[i].x, &job[i].y);
			if (d[1][job[i].x] == -1 || d[1][job[i].y] == -1) {
				blocked = 1;
			}
		}

		printf("Case #%d: ", r);
		if (blocked) {
			printf("-1\n");
		} else {
			printf("%d\n", wtf(0, 1, 0));
		}
	}
}
