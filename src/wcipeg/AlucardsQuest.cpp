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

int n, k, best;
vector<pii> adj[200005];
bool vis[200005], use[200005];

bool dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i].x] && dfs(adj[x][i].x))
			use[x] = 1;
	return use[x];
}

int all(int x) {
	vis[x] = 1;
	int ret = 0;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i].x] && use[adj[x][i].x])
			ret += all(adj[x][i].x) + adj[x][i].y;
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0, u, v, w; i < n - 1; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	for (int i = 0, x; i < k; i++) {
		scanf("%d", &x);
		use[x] = 1;
	}
	dfs(1);
	memset(vis, 0, sizeof vis);
	printf("%d", all(1));
}
