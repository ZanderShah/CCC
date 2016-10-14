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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n, bit[500005];
ll ans = 0;

void update(int x) {
	for (; x <= 500000; x += (x & (-x)))
		bit[x]++;
}

ll query(int x) {
	ll ret = 0;
	for (; x > 0; x -= (x & (-x)))
		ret += bit[x];
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		ll g = query(x - 1);
		ans += min(g, i - g);
		update(x);
	}
	printf("%lld", ans);
}