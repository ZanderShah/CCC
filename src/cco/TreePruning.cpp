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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef unordered_map<int, int> umii;

int N, D, dp[305][1005];
struct Node {
	int clr, b, w;
	int l, r, p;
} n[305];

void prep(int i) {
	if (n[i].clr == 0) {
		n[i].b++;
	} else {
		n[i].w++;
	}
	if (n[i].l) {
		prep(n[i].l);
		n[i].b += n[n[i].l].b;
		n[i].w += n[n[i].l].w;
	}
	if (n[i].r) {
		prep(n[i].r);
		n[i].b += n[n[i].r].b;
		n[i].w += n[n[i].r].w;
	}
}

int cut(int i, int d) {
	// Done
	if (d == 0)
		return 0;
	// Cut self
	if (d == n[i].w - n[i].b)
		return 1;

	if (dp[i][d + N] != -1)
		return dp[i][d + N];

	// Cut kids
	int ret = N + 1;
	if (n[i].l && n[i].r) {
		// Distribute load
		for (int j = min(0, d); j <= max(0, d); j++)
			ret = min(ret, cut(n[i].l, j) + cut(n[i].r, d - j));
	} else if (n[i].l) {
		ret = min(ret, cut(n[i].l, d));
	} else if (n[i].r) {
		ret = min(ret, cut(n[i].r, d));
	}

	return dp[i][d + N] = ret;
}

int main() {
	scanf("%d %d", &N, &D);

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= 2 * N; j++)
			dp[i][j] = -1;

	for (int i = 0, id, clr, kids; i < N; i++) {
		scanf("%d %d %d", &id, &clr, &kids);
		n[id].clr = clr;
		if (kids == 1) {
			scanf("%d", &n[id].l);
			n[n[id].l].p = id;
		} else if (kids == 2) {
			scanf("%d %d", &n[id].l, &n[id].r);
			n[n[id].l].p = n[n[id].r].p = id;
		}
	}

	prep(0);

	int minc = cut(0, n[0].w - n[0].b - D);
	printf("%d\n", minc <= N ? minc : -1);
}
