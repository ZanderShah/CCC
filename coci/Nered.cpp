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

int N, M, r, c, g[101][101], b = 1 << 30;

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &r, &c);
        g[r][c] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            g[i][j] = g[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    for (int k = 1; k <= M; k++) {
        if (M % k != 0) {
            continue;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int ii = i + k - 1, jj = j + M / k - 1;
                if (ii > N || jj > N) {
                    continue;
                }
                int s = g[ii][jj] - g[i - 1][jj] - g[ii][j - 1] + g[i - 1][j - 1];
                b = min(b, M - s);
            }
        }
    }
    printf("%d\n", b);
}
