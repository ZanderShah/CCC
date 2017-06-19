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

int N, M, d;
vector<vector<int> > v[10];

pii a = mp(1, 1), b = mp(1, 1);

void solve(int low, int up) {
    for (int j = 1; j <= M; j++) {
        for (int k = M; k >= j && (up - low + 1) * (k - j + 1) > (b.x - a.x + 1) * (b.y - a.y + 1); k--) {
            int chances = 2, nonZero = 0;
            for (int i = 0; i <= 9; i++) {
                int sum = v[i][up][k] - v[i][low - 1][k] - v[i][up][j - 1] + v[i][low - 1][j - 1];
                if (sum % 2) {
                    chances--;
                }
                if (sum >= 2 && i != 0) {
                    nonZero = 1;
                }
            }
            if (chances > 0 && nonZero) {
                a = mp(low, j);
                b = mp(up, k);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    N = n;
    M = m;
    if (n > m) {
        swap(N, M);
    }
    for (int i = 0; i <= 9; i++) {
        v[i].resize(N + 1);
        for (int j = 0; j <= N; j++) {
            v[i][j].resize(M + 1);
        }
    }
    bool allZero = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &d);
            if (n > m) {
                v[d][j][i] = 1;
            } else {
                v[d][i][j] = 1;
            }
            allZero &= !d;
        }
    }
    if (allZero) {
        printf("1\n");
        printf("0 0 0 0\n");
        return 0;
    }
    // Prefix sum for every digit
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                v[i][j][k] = v[i][j][k] + v[i][j - 1][k] + v[i][j][k - 1] - v[i][j - 1][k - 1];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= i && (j - i + 1) * M > (b.x - a.x + 1) * (b.y - a.y + 1); j--) {
            solve(i, j);
        }
    }
    printf("%d\n", (b.x - a.x + 1) * (b.y - a.y + 1));
    if (n > m) {
        swap(a.x, a.y);
        swap(b.x, b.y);
    }
    printf("%d %d %d %d\n", a.x - 1, a.y - 1, b.x - 1, b.y - 1);
}
