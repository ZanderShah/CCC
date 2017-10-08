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

int n, m, f, s, t, u, v;
ll d, dist[50005][2];
vector<pii> adj[50005];
priority_queue<pair<ll, int> > pq;
bool vis[50005][2];

void dijkstra(int x, int k) {
	dist[x][k] = 0;
	pq.push(mp(0, x));
	while (!pq.empty()) {
		int i = pq.top().y;
		pq.pop();
		vis[i][k] = 1;
		for (int j = 0; j < adj[i].size(); j++) {
			if (!vis[adj[i][j].x][k] && (dist[adj[i][j].x][k] == -1 || dist[adj[i][j].x][k] > dist[i][k] + adj[i][j].y)) {
				dist[adj[i][j].x][k] = dist[i][k] + adj[i][j].y;
				pq.push(mp(-dist[adj[i][j].x][k], adj[i][j].x));
			}
		}
	}
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &u, &v, &d);
        adj[u].pb(mp(v, d));
        adj[v].pb(mp(u, d));
    }
    memset(dist, -1, sizeof dist);
    memset(vis, 0, sizeof vis);
    dijkstra(s, 0);
    dijkstra(t, 1);
    d = dist[t][0];
    for (int i = 0; i < f; i++) {
        scanf("%d %d", &u, &v);
        if (dist[u][0] != -1 && dist[v][1] != -1 && (d == -1 || d > dist[u][0] + dist[v][1])) {
            d = dist[u][0] + dist[v][1];
        }
    }
    printf("%lld\n", d);
}
