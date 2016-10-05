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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n, v[101], m, best[101][1000001], dist[101];
vector<pii> adj[101];
pii ans;
bool vis[101];

void go(int x, int d, int c) {
	best[x][d] = max(best[x][d], c);
	dist[x] = min(dist[x], d);
	if (x == n) {
		if (ans.x > d)
			ans = mp(d, c);
		else if (ans.x == d)
			ans.y = max(ans.y, c);
	} else {
		vis[x] = 1;
		for (int i = 0; i < adj[x].size(); i++)
			if (!vis[adj[x][i].x] && d + adj[x][i].y <= dist[adj[x][i].x] && best[(int) adj[x][i].x][d + adj[x][i].y] < c + v[adj[x][i].x])
				go((int) adj[x][i].x, d + adj[x][i].y, c + v[adj[x][i].x]);
		vis[x] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		dist[i] = 1e9;
	}
	scanf("%d", &m);
	for (int i = 0, u, v, w; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	ans.x = 100001;
	go(1, 0, v[1]);
	if (ans.x == 100001)
		printf("impossible");
	else
		printf("%d %d", ans.x, ans.y);
}
