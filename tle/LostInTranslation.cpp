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

const int MAXN = 5005;

int n, m, c, dist[MAXN], ans = 0;
string s, t;
unordered_map<string, int> my;
vector<pii> adj[MAXN];
vector<int> order[MAXN];
bool vis[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	my["English"] = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		my[s] = i;
		dist[i] = MAXN;
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> t >> c;
		adj[my[s]].pb(mp(my[t], c));
		adj[my[t]].pb(mp(my[s], c));
	}

	// Get shortest path to English
	while (1) {
		int i = -1, b = MAXN;
		for (int j = 0; j <= n; j++) {
			if (!vis[j] && dist[j] < b) {
				i = j;
				b = dist[j];
			}
		}
		if (b == MAXN) {
			break;
		}
		for (int j = 0; j < adj[i].size(); j++) {
			if (!vis[adj[i][j].x] && dist[adj[i][j].x] > dist[i] + 1) {
				dist[adj[i][j].x] = dist[i] + 1;
			}
		}
		vis[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == MAXN) {
			printf("Impossible\n");
			return 0;
		}
		order[dist[i]].pb(i);
	}

	memset(vis, 0, sizeof vis);
	vis[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j < order[i].size(); j++) {
			int b = MAXN;
			for (int k = 0; k < adj[order[i][j]].size(); k++) {
				if (vis[adj[order[i][j]][k].x]) {
					b = min(b, adj[order[i][j]][k].y);
				}
			}
			ans += b;
		}
		for (int j = 0; j < order[i].size(); j++) {
			vis[order[i][j]] = 1;
		}
	}
	printf("%d\n", ans);
}
