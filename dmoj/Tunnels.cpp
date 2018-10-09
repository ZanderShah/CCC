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
int N, T, d = 0;
vector<pii> adj[MAXN];
pii up[MAXN], down_first[MAXN], down_second[MAXN];

int pre(int i, int p) {
    down_first[i] = down_second[i] = up[i] = mp(0, -1);

    for (pii j : adj[i]) {
        if (j.x != p) {
            int d = pre(j.x, i) + j.y;
            if (down_first[i].x < d) {
                down_second[i] = down_first[i];
                down_first[i] = mp(d, j.x);
            } else if (down_second[i].x < d) {
                down_second[i] = mp(d, j.x);
            }
        }
    }

    return down_first[i].x;
}

void post(int i, int p) {
    for (pii j : adj[i]) {
        if (j.x != p) {
            if (down_first[i].y == j.x) {
                up[j.x].x = max(up[i].x, down_second[i].x) + j.y;
            } else {
                up[j.x].x = max(up[i].x, down_first[i].x) + j.y;
            }
            post(j.x, i);
        }
    }
}

int main() {
    scanf("%d %d", &N, &T);
    for (int i = 0, a, b, c; i < N - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        d += c;
    }
    pre(1, 1);
    post(1, 1);

    for (int i = 1; i <= N; i++) {
        if (adj[i].size() == T) {
            printf("%d %d\n", i, 2 * d - max(up[i].x, down_first[i].x));
        }
    }
}