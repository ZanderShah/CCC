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

int R, S, l[505][505], r[505][505], G, rr, c;
string s;

void update(int x, int y) {
	for (int i = 1; i <= S; i++) {
		if (i >= y && (abs(i - y) < abs(l[x][i] - i) || l[x][y] == -1)) {
			l[x][i] = y;
		}
		if (i <= y && (abs(i - y) < abs(r[x][i] - i) || r[x][i] == -1)) {
			r[x][i] = y;
		}
	}
}

int main() {
	scanf("%d %d", &R, &S);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= S; j++) {
			l[i][j] = r[i][j] = -1;
		}
	}
	for (int i = 1; i <= R; i++) {
		cin >> s;
		for (int j = 1; j <= S; j++) {
			if (s[j - 1] == 'x') {
				update(i, j);
			}
		}
	}
	scanf("%d", &G);

	for (int t = 0; t < G; t++) {
		scanf("%d %d", &rr, &c);
		int d = 1e9;
		for (int i = 1; i <= R; i++) {
			if (l[i][c] != -1) {
				d = min(d, (rr - i) * (rr - i) + (c - l[i][c]) * (c - l[i][c]));
			}
			if (r[i][c] != -1) {
				d = min(d, (rr - i) * (rr - i) + (c - r[i][c]) * (c - r[i][c]));
			}
		}
		update(rr, c);
		printf("%d\n", d);
	}
}
