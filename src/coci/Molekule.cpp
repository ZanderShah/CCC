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

const int MAXN = 1e5 + 5;
int n, colour[MAXN];
vector<int> adj[MAXN];
vector<pii> edge;

void dfs(int x, int c) {
	colour[x] = c;
	for (int i = 0; i < adj[x].size(); i++)
		if (!colour[adj[x][i]]) {
			dfs(adj[x][i], c ^ 3);
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		adj[v].pb(u);
		adj[u].pb(v);
		edge.pb(mp(u, v));
	}
	dfs(1, 1);
	for (int i = 0; i < n - 1; i++)
		printf("%d\n", colour[edge[i].x] == 2);
}
