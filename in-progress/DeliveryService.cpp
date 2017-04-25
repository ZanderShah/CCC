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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int X, D, N, P, W, added;
ll bit[MAXN];
pii p[MAXN];

void update(int x, int v) {
	for (; x <= D; x += x & -x) {
		bit[x] = (bit[x] + v) % MOD;
	}
}

ll query(int x) {
	ll ret = 0;
	for (; x; x -= x & -x) {
		ret = (ret + bit[x]) % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &X);
	if (X == 1) {
		scanf("%d %d %d", &D, &N, &P);
		for (int i = 0; i < P; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		sort(p, p + P);

		update(D, 1);
		for (int i = P - 1; i >= 0; i--) {
			update(p[i].x, query(min(D, p[i].x + p[i].y) - query(p[i].x - 1)));
		}

		printf("%lld\n", query(N));
	} else {
		scanf("%d", &W);

		D = N = P = 69;

		for (int i = 1; i < P; i++) {
			p[i].x = i;
		}

		update(D, 1);
		for (int i = P - 1; i >= 1; i--) {
			// Number of paths added will be query(x + y) - query(x - 1)
			for (int j = D - p[i].x; j >= 1; j--) {
				added = query(p[i].x + j) - query(p[i].x - 1);
				update(p[i].x, added);

				if (query(N) <= W) {
					p[i].y = j;
					break;
				} else {
					update(p[i].x, -added);
				}
			}
		}

		printf("%d %d %d\n", D, N, P - 1);
		for (int i = 1; i < P; i++) {
			printf("%d %d\n", p[i].x, p[i].y);
		}
	}
}
