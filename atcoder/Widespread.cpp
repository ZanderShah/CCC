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

int N, A, B, h[100005];

bool dead(int t) {
    ll u = 0;
    for (int i = 0; i < N; i++) {
        u += ceil(max(h[i] - 1ll * t * B, 0ll) * 1.0 / (A - B));
    }
    return u <= t;
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }
    int lo = 1, hi = 1 << 30, mid = (lo + hi) >> 1;
    while (lo <= hi) {
        if (dead(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        mid = (lo + hi) >> 1;
    }
    printf("%d\n", lo);
}
