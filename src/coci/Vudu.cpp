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

const int MAXN = 1000005;

int N, P, bit[MAXN];
pll a[MAXN];
ll ans;

inline void update(int x) {
	x += 5;

	for (; x < MAXN; x += x & -x) {
		bit[x]++;
	}
}

inline int query(int x) {
	x += 5;

	int ret = 0;
	for (; x; x -= x & -x) {
		ret += bit[x];
	}
	return ret;
}

int main() {
	scan(N);
	for (int i = 1; i <= N; ++i) {
		scan(a[i].x);
		a[i].y = i;
	}
	scan(P);

	for (int i = 1; i <= N; ++i) {
		a[i].x += a[i - 1].x - P;
	}
	sort(a, a + N + 1);

	for (int i = 0; i <= N; ++i) {
		ans += query(a[i].y);
		update(a[i].y);
	}
	printf("%lld\n", ans);
}
