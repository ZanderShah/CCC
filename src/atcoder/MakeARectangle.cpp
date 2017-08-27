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

int N;
umii A;
vector<int> p;

int main() {
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        A[x] += 1;
        if (A[x] % 2 == 0) {
            p.pb(x);
        }
    }
    sort(p.begin(), p.end());

    if (p.size() <= 1) {
        printf("0\n");
        return 0;
    }

    printf("%lld\n", 1ll * p[p.size() - 1] * p[p.size() - 2]);
}
