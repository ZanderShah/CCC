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

int N, M, K, p[101], s, ans;
float c[201];

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + N);
    for (int i = 0; i < M; i++) {
        scanf("%f", &c[i]);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &s);
        c[M + i] = sqrt(s * s * 1.0 / 2);
    }
    sort(c, c + M + K);
    for (int i = 0, j = 0; i < N; i++) {
        if (j < M + K && c[j] < p[i]) {
            j++;
            ans++;
        }
    }
    printf("%d\n", ans);
}
