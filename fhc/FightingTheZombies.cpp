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

int T, N, R, ans;
pii x[55];
vector<bitset<55> > s;
bitset<55> e;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; r++) {
		s.clear();
		scanf("%d %d", &N, &R);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x[i].x, &x[i].y);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				e.reset();
				for (int k = 0; k < N; k++) {
					if (x[k].x - x[i].x >= 0 && x[k].x - x[i].x <= R
					    && x[j].y - x[k].y >= 0 && x[j].y - x[k].y <= R) {
						e[k] = 1;
					}
				}
				s.pb(e);
			}
		}

		ans = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				e = s[i] | s[j];
				ans = max(ans, (int) e.count());
			}
		}

		printf("Case #%d: %d\n", r, ans);
	}
}
