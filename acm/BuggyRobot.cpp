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

int H, W, t, x;
char g[52][52];
int dp[50][50][51][1501];
pii s, e;
string c;

bool valid(int x, int y, int i, int l) {
    if (dp[x - 1][y - 1][i][l] != -1) {
        return dp[x - 1][y - 1][i][l];
    }
    if (g[x][y] == 'G') {
        return 1;
    }
    if (c.length() <= i && l == 0) {
        return 0;
    }

    bool ret = 0;
    if (i < c.length()) {
        if (c[i] == 'L') {
            ret |= valid(x, y - (g[x][y - 1] != '#'), i + 1, l);
        }
        if (c[i] == 'R') {
            ret |= valid(x, y + (g[x][y + 1] != '#'), i + 1, l);
        }
        if (c[i] == 'U') {
            ret |= valid(x - (g[x - 1][y] != '#'), y, i + 1, l);
        }
        if (c[i] == 'D') {
            ret |= valid(x + (g[x + 1][y] != '#'), y, i + 1, l);
        }
    }

    if (l >= 1) {
        if (g[x][y - 1] != '#') {
            ret |= valid(x, y - 1, i, l - 1);
        } 
        if (g[x][y + 1] != '#') {
            ret |= valid(x, y + 1, i, l - 1);
        } 
        if (g[x - 1][y] != '#') {
            ret |= valid(x - 1, y, i, l - 1);
        } 
        if (g[x + 1][y] != '#') {
            ret |= valid(x + 1, y, i, l - 1);
        } 
        ret |= valid(x, y, i, l - 1);
    }

    return dp[x - 1][y - 1][i][l] = ret;
}

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            g[i][j] = '#';
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == 'S') {
                s = mp(i, j);
            } else if (g[i][j] == 'G') {
                e = mp(i, j);
            }
        }
    }
    cin >> c;
    memset(dp, -1, sizeof dp);
    valid(s.x, s.y, 0, 1500);
    for (int i = 0; 1; i++) {
        if (dp[s.x - 1][s.y - 1][0][i]) {
            printf("%d\n", i);
            return 0;
        }
    }
}
