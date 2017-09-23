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

int N, K, x, t;
ll d;
vector<pii> neg, pos;

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &t);
        if (x < 0) {
            neg.pb(mp(-x, t));
        } else if (x > 0) {
            pos.pb(mp(x, t));
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    for (int i = neg.size() - 1, j = 0; i >= 0; i--) {
        x = neg[i].x;
        t = neg[i].y;
        while (t > j) {
            d += 2 * x;
            t -= j;
            j = K;
        }
        j -= t;
    }
    for (int i = pos.size() - 1, j = 0; i >= 0; i--) {
        x = pos[i].x;
        t = pos[i].y;
        while (t > j) {
            d += 2 * x;
            t -= j;
            j = K;
        }
        j -= t;
    }

    printf("%lld\n", d);
}
