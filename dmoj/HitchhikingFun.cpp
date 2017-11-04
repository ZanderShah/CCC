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
int N, M, u, v, t, dist[MAXN], danger[MAXN];
vector<pii> adj[100005];
priority_queue<pair<pii, int>> pq;
bool vis[100005];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &t);
        adj[u].pb(mp(v, t));
        adj[v].pb(mp(u, t));
    }
    for (int i = 2; i <= N; i++) {
        dist[i] = 1 << 30;
        danger[i] = 1 << 30;
    }
    pq.push(mp(mp(-danger[1], -dist[1]), 1));
    while (!pq.empty()) {
        u = pq.top().y;
        pq.pop();

        vis[u] = 1;

        for (int j = 0; j < adj[u].size(); j++) if (!vis[adj[u][j].x]) {
            v = adj[u][j].x;
            if (danger[v] > danger[u] + adj[u][j].y || (danger[v] == danger[u] + adj[u][j].y && dist[v] > dist[u] + 1)) {
                danger[v] = danger[u] + adj[u][j].y;
                dist[v] = dist[u] + 1;
                pq.push(mp(mp(-danger[v], -dist[v]), v));
            }
        }
    }

    if (danger[N] == 1 << 30) {
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n", danger[N], dist[N]);
}
