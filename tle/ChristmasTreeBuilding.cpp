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

struct Node {
	int r, p;
	Node(int pp) {
		r = 0;
		p = pp;
	}
};
vector<Node> v;

int find(int x) {
	if (v[x].p != x)
		v[x].p = find(v[x].p);
	return v[x].p;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (v[x].r < v[y].r) {
		v[x].p = y;
	} else if (v[x].r > v[y].r) {
		v[y].p = x;
	} else {
		v[y].p = x;
		v[x].r++;
	}
}

int N, M, Q, vis[100005];
bool mark[100005];
vector<pll> adj[100005];
pll opt;
ll ml;
vector<ll> mls;

void dfs(int i, ll l, int t) {
	if (opt.y < l)
		opt = mp(i, l);
	vis[i] = t;
	for (int j = 0; j < adj[i].size(); j++)
		if (vis[adj[i][j].x] != t)
			dfs(adj[i][j].x, l + adj[i][j].y, t);
}

int markPath(int a, int b) {
	if (a == b)
		return mark[a] = 1;
	vis[a] = 3;
	bool ret = 0;
	for (int i = 0; i < adj[a].size(); i++)
		if (vis[adj[a][i].x] != 3)
			ret |= markPath(adj[a][i].x, b);
	return mark[a] = ret;
}

ll findMin(int a, ll l) {
	ll ret = max(l, opt.y - l);
	vis[a] = 4;
	for (int i = 0; i < adj[a].size(); i++)
		if (vis[adj[a][i].x] != 4 && mark[adj[a][i].x])
			ret = min(ret, findMin(adj[a][i].x, l + adj[a][i].y));
	return ret;
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i = 0; i <= N; i++)
		v.pb(Node(i));
	for (int i = 0, u, v, l; i < M; i++) {
		scanf("%d %d %d", &u, &v, &l);
		merge(u, v);
		adj[u].pb(mp(v, l));
		adj[v].pb(mp(u, l));
	}

	if (Q == 1) {
		ml = -1;
		for (int i = 1; i <= N; i++) {
			if (!vis[find(i)]) {
				opt.y = -1;
				dfs(i, 0, 1);
				opt.y = -1;
				dfs(opt.x, 0, 2);
				ml += opt.y + 1;
			}
		}
	} else if (Q == 2) {
		for (int i = 1; i <= N; i++) {
			if (!vis[find(i)]) {
				opt.y = -1;
				dfs(i, 0, 1);
				ll a = opt.x;
				opt.y = -1;
				dfs(a, 0, 2);

				// Mark longest path
				markPath(a, opt.x);
				mls.pb(findMin(a, 0));
			}
		}
		sort(mls.begin(), mls.end());
		ml = mls.back();
		for (int i = 0; i < mls.size() - 1; i++)
			ml = max(ml, mls[i] + 1);
	}

	printf("%lld\n", ml);
}
