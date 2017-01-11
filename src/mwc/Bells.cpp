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
#include <stdio.h>

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

queue<int> fre;
bitset<1005> seg[300005], empty;
umii m, tot;
int N, Q, val[100005];

void update(int i, int cL, int cR, int x, int o, int f) {
	if (cL > x || cR < x)
		return;

	if (cL == x && cR == x) {
		seg[i][o] = 0;
		seg[i][f] = 1;
		return;
	}

	int m = (cL + cR) / 2;
	update(l(i), cL, m, x, o, f);
	update(r(i), m + 1, cR, x, o, f);

	seg[i] = seg[l(i)] | seg[r(i)];
}

bitset<1005> query(int i, int cL, int cR, int l, int r) {
	if (cL > r || cR < l)
		return empty;

	if (cL >= l && cR <= r) {
		return seg[i];
	}

	int m = (cL + cR) / 2;
	return query(l(i), cL, m, l, r) | query(r(i), m + 1, cR, l, r);
}

int main() {
	for (int i = 1; i <= 1500; i++)
		fre.push(i);

	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &val[i]);
		if (m.find(val[i]) == m.end()) {
			m[val[i]] = fre.front();
			fre.pop();
		}
		tot[val[i]]++;
		update(1, 1, N, i, m[val[i]], m[val[i]]);
	}

	for (int i = 1, c, l, r; i <= Q; i++) {
		scanf("%d %d %d", &c, &l, &r);
		if (c == 1 && l != r) {
			// Map r if it is not mapped already
			if (m.find(r) == m.end()) {
				m[r] = fre.front();
				fre.pop();
			}

			// Update segtree
			update(1, 1, N, l, m[val[l]], m[r]);

			// Update total count of old, add to queue if its 0
			// Update total count of new
			tot[val[l]]--;
			if (tot[val[l]] == 0) {
				fre.push(m[val[l]]);
			}
			val[l] = r;
			tot[val[l]]++;
		} else if (c == 2) {
			printf("%d\n", query(1, 1, N, l, r).count());
		}
	}
}
