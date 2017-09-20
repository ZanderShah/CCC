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

const int MAXN = 100005;
int N, M, B[MAXN];
ull ans = 0, L[MAXN], sum[MAXN];
priority_queue<int> pq[MAXN];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &B[i], &sum[i], &L[i]);
        pq[i].push(sum[i]);
    }
    for (int i = N; i >= 1; i--) {
        ans = max(ans, L[i] * pq[i].size());

        if (pq[i].size() > pq[B[i]].size()) {
            swap(pq[i], pq[B[i]]);
        }
        while (!pq[i].empty()) {
            pq[B[i]].push(pq[i].top());
            pq[i].pop();
        }
        sum[B[i]] += sum[i];
        while (sum[B[i]] > M) {
            sum[B[i]] -= pq[B[i]].top();
            pq[B[i]].pop();
        }
    }
    printf("%lld\n", ans);
}
