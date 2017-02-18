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
#include <cstdio>
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
typedef unordered_map<int, int> umii;

int N, M;
vector<pii> adj[1005];
ll d[1005], views[1005];
priority_queue<pii> pq;

int main () {
	scanf("%d %d", &N, &M);

	for (int i = 0, a, b, d; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		adj[a].pb(mp(b, -d));
	}

	// Bellman-Ford
	for (int i = 2; i <= N; i++) {
		d[i] = 1 << 30;
	}
	views[1] = 1;
	for (int r = 0; r < N - 1; r++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (d[i] != 1 << 30 && d[i] + adj[i][j].y < d[adj[i][j].x]) {
					d[adj[i][j].x] = d[i] + adj[i][j].y;
					views[adj[i][j].x] = views[i] + 1;
				} else if (d[i] != 1 << 30 && d[i] + adj[i][j].y == d[adj[i][j].x]) {
					views[adj[i][j].x] = max(views[adj[i][j].x], views[i] + 1);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (d[i] != 1 << 30 && d[i] + adj[i][j].y < d[adj[i][j].x]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%lld %lld", -d[N], views[N]);
}
