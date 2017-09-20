#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

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

const int MAXN = 100005;

int n, c, k, v[MAXN], size[MAXN], weight[MAXN];
vector<pii> adj[MAXN];
bool vis[MAXN];

int getSize(int x) {
	vis[x] = 1;
	int ret = v[x];
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i].x])
			ret += getSize(adj[x][i].x);
	return size[x] = ret;
}

void getWeight(int x) {
	vis[x] = 1;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i].x]) {
			weight[adj[x][i].x] += adj[x][i].y;
			getWeight(adj[x][i].x);
		}
}

int fillWeight(int x) {
	vis[x] = 1;
	int ret = weight[x];
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i].x])
			ret += fillWeight(adj[x][i].x);
	return weight[x] = ret;
}

int main() {
	scanf("%d %d %d", &n, &c, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 0, a, b, w; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
	}
	getSize(1);
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	getWeight(1);
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	fillWeight(1);
	int cuts = 0;
	for (int i = 2; i <= n; i++)
		if (size[i] >= c && weight[i] <= k)
			cuts++;
	printf("%d", cuts);
}
