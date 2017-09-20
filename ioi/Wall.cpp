#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

struct Node {
	int up, down;
} seg[5000001];

inline void pushDown(int c, int p) {
	seg[c].down = min(seg[c].down, seg[p].down);
	seg[c].down = max(seg[c].down, seg[p].up);
	seg[c].up = max(seg[c].up, seg[p].up);
	seg[c].up = min(seg[c].up, seg[p].down);
}

void update(int i, int cL, int cR, int l, int r, int t, int h) {
	if (cL > r || cR < l)
		return;

	if (cL >= l && cR <= r) {
		if (t == 1) {
			seg[i].down = max(seg[i].down, h);
			seg[i].up = max(seg[i].up, h);
		} else {
			seg[i].down = min(seg[i].down, h);
			seg[i].up = min(seg[i].up, h);
		}
		return;
	}

	pushDown(l(i), i);
	pushDown(r(i), i);
	seg[i].down = 1e9;
	seg[i].up = 0;

	int m = (cL + cR) / 2;
	update(l(i), cL, m, l, r, t, h);
	update(r(i), m + 1, cR, l, r, t, h);
}

int query(int i, int cL, int cR, int x) {
	if (cL > x || cR < x)
		return 1e9;

	if (cL == x && cR == x)
		return min(seg[i].down, seg[i].up);

	pushDown(l(i), i);
	pushDown(r(i), i);

	int m = (cL + cR) / 2;
	return min(query(l(i), cL, m, x), query(r(i), m + 1, cR, x));
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[],
		int finalHeight[]) {

	for (int i = 0; i < k; i++)
		update(1, 1, n, left[i] + 1, right[i] + 1, op[i], height[i]);

	for (int i = 0; i < n; i++)
		finalHeight[i] = query(1, 1, n, i + 1);
}
