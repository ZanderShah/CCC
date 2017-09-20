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

const int MOD = 1e9 + 7, MAXN = 1e5 + 5;
ll N, A0, B, M;
ll ans = 0, F, L, R;

int main() {
    scanf("%lld %lld %lld %lld", &N, &A0, &B, &M);
    L = R = 0;
    F = A0;
    for (int i = 2; i <= N; i++) {
        F = F * B % M;
        R = (R + F) % MOD;
    }
    F = A0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + L * F % MOD) % MOD;
        ans = (ans + R * F % MOD) % MOD;
        L = (L + F) % MOD;
        F = F * B % M;
        R = (R - F + MOD) % MOD;
    }
    printf("%lld\n", ans);
}
