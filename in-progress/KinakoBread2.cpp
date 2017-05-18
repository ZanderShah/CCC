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

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int N, Lk, Rk, Lc, Rc, size[MAXN], root, paths = 0, bit[MAXN];
bool vis[MAXN], dead[MAXN];
char s[MAXN];
vector<int> laggingPath;

void update(int x) {
	for (; x <= N; x += x & -x) {
		bit[x]++;
	}
}

int query(int x) {
	if (x <= 0) {
		return 0;
	}
	int ret = 0;
	for (; x; x -= x & -x) {
		ret += bit[x];
	}
	return ret;
}

void reset() {
	for (int i = 0; i < N; i++) {
		vis[i] = dead[i];
	}
}

int pre(int i) {
	vis[i] = 1;

	int ret = 1;
	for (int j = 0; j < adj[i].size(); j++) {
		if (!vis[adj[i][j]]) {
			ret += pre(adj[i][j]);
		}
	}
	return size[i] = ret;
}

int centroid(int i) {
	vis[i] = 1;
	for (int j = 0; j < adj[i].size(); j++) {
		if (!vis[adj[i][j]] && size[adj[i][j]] * 2 >= size[root]) {
			return centroid(adj[i][j]);
		}
	}
	return i;
}

void go(int i, int b) {
	vis[i] = 1;
	laggingPath.pb(b);

	// Range of [Lk, Rk] => [Lk - b, Rk - b]
	paths += query(Rk - b) - query(Lk - b - 1);

	for (int j = 0; j < adj[i].size(); j++) {
		if (!vis[adj[i][j]]) {
			go(adj[i][j], b + 1);
			// if (s[adj[i][j]] == 'K') {
			//      go(adj[i][j], b + 1, c);
			// } else {
			//      go(adj[i][j], b, c + 1);
			// }
		}
	}
}

void solve(int i) {
	root = i;

	// Precompute subtree sizes
	reset();
	pre(i);

	reset();
	int c = centroid(i);

	if (Lk <= 1 && 1 <= Rk) {
		paths++;
	}

	// Calculate number of paths going through centroid

	// All bread being kinako bread subtask
	reset();
	memset(bit, 0, sizeof bit);
	update(1);

	for (int j = 0; j < adj[c].size(); j++) {
		if (!dead[adj[c][j]]) {
			laggingPath.clear();

			go(adj[c][j], 1);
			// if (s[adj[c][j]] == 'K') {
			//      go(adj[c][j], 1, 0);
			// } else {
			//      go(adj[c][j], 0, 1);
			// }

			for (int k = 0; k < laggingPath.size(); k++) {
				update(laggingPath[k] + 1);
			}
		}
	}

	dead[c] = 1;
	for (int j = 0; j < adj[c].size(); j++) {
		if (!dead[adj[c][j]]) {
			solve(adj[c][j]);
		}
	}
}

int main() {
	scanf("%d %d %d %d %d", &N, &Lk, &Rk, &Lc, &Rc);
	scanf(" %s", s);
	for (int i = 0, u, v; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	solve(0);
	printf("%d\n", paths);
}
