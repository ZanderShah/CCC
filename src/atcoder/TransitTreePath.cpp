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
int N, a, b, c, Q, K;
vector<pii> adj[MAXN];
ll dist[MAXN];

void dfs(int i, int p, ll d) {
    dist[i] = d;
    for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j].x != p) {
            dfs(adj[i][j].x, i, d + adj[i][j].y);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    scanf("%d %d", &Q, &K);
    dfs(K, K, 0);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", dist[a] + dist[b]);
    }
}
