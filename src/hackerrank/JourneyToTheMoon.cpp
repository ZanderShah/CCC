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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
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
typedef unordered_map<int, int> umii;

struct Node {
	int p, r, sz;
} v[100005];

int find(int x) {
	if (v[x].p != x)
		v[x].p = find(v[x].p);
	return v[x].p;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (v[x].r < v[y].r) {
		v[x].p = y;
		v[y].sz += v[x].sz;
	} else if (v[x].r > v[y].r) {
		v[y].p = x;
		v[x].sz += v[y].sz;
	} else {
		v[y].p = x;
		v[x].sz += v[y].sz;
		v[x].r++;
	}
}

int N, I;
bool vis[100005];

int main() {
	scanf("%d %d", &N, &I);
	for (int i = 0; i < N; i++) {
		v[i] = Node { i, 0, 1 };
	}
	for (int i = 0, a, b; i < I; i++) {
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[find(i)]) {
			ret += v[find(i)].sz * (N - v[find(i)].sz);
			vis[find(i)] = 1;
		}
	}
	printf("%lld\n", ret / 2);
}
