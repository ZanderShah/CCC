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
#include "secret.h"

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

const int MAXN = 1e3 + 5;
int pre[MAXN][MAXN];

void split(int l, int r) {
    if (r <= l) {
        return;
    }
    int m = (l + r) / 2;
    for (int i = m - 1; i >= l; i--) {
        pre[i][m] = Secret(pre[i][i], pre[i + 1][m]);
    }
    for (int i = m + 2; i <= r; i++) {
        pre[m + 1][i] = Secret(pre[m + 1][i - 1], pre[i][i]);
    }
    split(l, m);
    split(m + 1, r);
}

void Init(int N, int A[]) {
    memset(pre, -1, sizeof pre);
    for (int i = 0; i < N; i++) {
        pre[i][i] = A[i];
    }
    split(0, N - 1);
}

int Query(int L, int R) {
    for (int i = L; i < R; i++) {
        if (pre[L][i] != -1 && pre[i + 1][R] != -1) {
            return Secret(pre[L][i], pre[i + 1][R]);
        }
    }
    return pre[L][R];
}
