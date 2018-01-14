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
int N, M, K, h[MAXN], s[MAXN];

bool valid(ll H) {
    memset(s, 0, sizeof s);
    int k = 0, c = 0;
    for (int i = 1; i <= N; i++) {
        c -= s[i];
        // Snowman is already above target height
        if (H - h[i] - c <= 0) continue;
        // Required amount is over limit
        if (H - h[i] - c + k > K) return false;
        k += H - h[i] - c;
        if (i + M <= N) s[i + M] += H - h[i] - c;
        c = H - h[i];
    }
    return true;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &h[i]);
    }
    ll lo = 0, hi = 1ll << 60, mid = (lo + hi) >> 1;
    while (lo <= hi) {
        if (valid(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        mid = (lo + hi) >> 1;
    }
    printf("%lld\n", mid);
}
