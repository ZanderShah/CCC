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

const int MAXN = 8005;
int n, q, v[MAXN], x, y, p[2 * MAXN], sub = 0, vv, d = 0;
umii c;
unordered_map<int, umii> memo;
vector<int> jump[MAXN];

int main() {
    scan(n); scan(q);
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        scan(vv);
        if (c.find(vv) == c.end()) {
            c[vv] = ++j;
            v[i] = j;
        } else {
            v[i] = c[vv];
        }
        jump[v[i]].pb(i);
    }
    for (int qq = 0; qq < q; ++qq) {
        scan(x); scan(y);
        sub = 0;
        
        if ((c.find(x) == c.end() && c.find(y) == c.end()) || x == y) {
            printf("%d\n", n * (n + 1) / 2);
            continue;
        }

        x = c[x];
        y = c[y];
        
        if (jump[x].size() == 0 || jump[x].back() != n + 1) {
            jump[x].pb(n + 1);
        }
        if (jump[y].size() == 0 || jump[y].back() != n + 1) {
            jump[y].pb(n + 1);
        }
        
        if (memo[min(x, y)].find(max(x, y)) != memo[min(x, y)].end()) {
            printf("%d\n", memo[min(x, y)][max(x, y)]);
            continue;
        }

        memset(p, 0, sizeof p);
        int c = 0;
        
        d = min(jump[x][0], jump[y][0]) - 1;
        sub += d * p[n] + d * (d - 1) / 2;
        p[n] += d;

        for (int i = 0, j = 0; jump[x][i] <= n || jump[y][j] <= n; ) {
            if (jump[x][i] < jump[y][j]) {
                c++;
                d = min(jump[x][i + 1], jump[y][j]) - jump[x][i];
                i++;
            } else {
                c--;
                d = min(jump[y][j + 1], jump[x][i]) - jump[y][j];
                j++;
            }
            sub += d * p[c + n] + d * (d - 1) / 2;
            p[c + n] += d;
        }

        sub += p[n];

        memo[min(x, y)][max(x, y)] = sub;
        printf("%d\n", sub);
    }
}