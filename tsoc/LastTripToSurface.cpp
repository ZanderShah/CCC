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

int N, b, g, t;
pii c[505];
queue<pii> q;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c[i].x, &c[i].y);
		q.push(c[i]);
		t = __gcd(t, c[i].x);
		b += c[i].y;
	}
	if (t != 1) {
		printf("Hooray!\n");
		return 0;
	}

	while (!q.empty()) {
		pii x = q.front();
		q.pop();

		if (x.x == 1) {
			b = min(b, x.y);
		}
		if (b <= x.y) {
			continue;
		}

		for (int i = 0; i < N; i++) {
			g = __gcd(x.x, c[i].x);
			if (x.x != g) {
				q.push(mp(g, x.y + c[i].y));
			}
		}
	}

	printf("%d\n", b);
}
