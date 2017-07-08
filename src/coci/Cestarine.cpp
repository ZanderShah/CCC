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
const ll INF = 1ll << 60;

int N, L[MAXN], R[MAXN];
ll dp[MAXN];

ll ans(int i, int j) {
    vector<int> exits;
    for (int k = i - j; k <= i; k++) {
        exits.pb(R[k]);
    } 
    
    ll ret = INF;
    do {
        ll cur = 0;
        for (int k = 0; k <= j; k++) {
            cur += L[i - j + k] != exits[k] ? abs(L[i - j + k] - exits[k]) : INF;
        }
        ret = min(ret, cur);
    } while (next_permutation(exits.begin(), exits.end()));

    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &L[i], &R[i]);
    }
    sort(L + 1, L + 1 + N);
    sort(R + 1, R + 1 + N);

    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
        for (int j = 0; j <= 2 && i - j >= 1; j++) {
            dp[i] = min(dp[i], dp[i - j - 1] + ans(i, j));
        }
    }

    printf("%lld\n", dp[N]); 
}
