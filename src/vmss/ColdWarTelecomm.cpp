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

const int MAXN = 1e5 + 5;

int N, M, k = 0, first[MAXN], low[MAXN];
vector<int> adj[MAXN];
set<int> art;
bool vis[MAXN];

void dfs(int i, int p) {
	vis[i] = 1;
	low[i] = first[i] = k++;
	int child = 0;

	for (int j = 0; j < adj[i].size(); j++) {
		if (adj[i][j] == p) {
			continue;
		}

		if (vis[adj[i][j]]) {
			low[i] = min(low[i], first[adj[i][j]]);
		} else {
			dfs(adj[i][j], i);
			low[i] = min(low[i], low[adj[i][j]]);
			child++;

			if (low[adj[i][j]] >= first[i] && p != -1) {
				art.insert(i);
			}
		}
	}

	if (p == -1 && child > 1) {
		art.insert(i);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	memset(vis, 0, sizeof vis);
	for (int i = 0, u, v; i < M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1);
	printf("%d\n", art.size());
	for (auto it = art.begin(); it != art.end(); it++) {
		printf("%d\n", *it);
	}
}
