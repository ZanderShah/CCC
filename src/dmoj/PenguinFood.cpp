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

const int MAXN = 1e6 + 5;

int N, a[MAXN], M;

struct Node {
	int l, r;
	int lv, rv, mv, sum;
} seg[3 * MAXN];

void update(int i, int l, int r, int x) {
	if (l > x || r < x) {
		return;
	}
	if (l == r) {
		seg[i].sum = a[l];
		seg[i].lv = seg[i].rv = seg[i].mv = max(0, a[l]);
		return;
	}
	int m = (l + r) / 2;
	update(l(i), l, m, x);
	update(r(i), m + 1, r, x);
	seg[i].sum = seg[l(i)].sum + seg[r(i)].sum;
	seg[i].lv = max(seg[l(i)].lv, seg[l(i)].sum + seg[r(i)].lv);
	seg[i].rv = max(seg[r(i)].rv, seg[r(i)].sum + seg[l(i)].rv);

	seg[i].mv = max(seg[i].rv, seg[i].lv);
	seg[i].mv = max(seg[i].mv, seg[i].sum);
	seg[i].mv = max(seg[i].mv, seg[l(i)].rv + seg[r(i)].lv);
	seg[i].mv = max(seg[i].mv, seg[l(i)].mv);
	seg[i].mv = max(seg[i].mv, seg[r(i)].mv);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		update(1, 1, N, i);
	}
	printf("%d\n", seg[1].mv);

	scanf("%d", &M);
	for (int i = 0, x, y; i < M; i++) {
		scanf("%d %d", &x, &y);
		x++;
		a[x] = y;
		update(1, 1, N, x);
		printf("%d\n", seg[1].mv);
	}
}
