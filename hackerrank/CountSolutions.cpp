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
#include <cassert>

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

int q;
ll a, b, c, d;

int main() {
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int ans = 0;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        // brute();
        for (ll x = 1; x <= c; x++) {
            ll C = x * x - x * a;

            if (b * b - 4 * C < 0) {
                continue;
            } else if (b * b - 4 * C == 0) {
                ans += 1;
            } else {
                ll sq = round(sqrt(b * b - 4 * C));
                if (sq * sq != b * b - 4 * C) {
                    continue;
                }
                if (2 <= b + sq && b + sq <= 2 * d && (b + sq) % 2 == 0) {
                    ans++;
                } 
                if (2 <= b - sq && b - sq <= 2 * d && (b - sq) % 2 == 0) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
