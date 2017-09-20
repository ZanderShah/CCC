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

const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, x;
queue<pii> q;

map<pii, map<pii, bool> > vis;

inline bool valid(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
	scanf("%d", &N);
	q.push(mp(1, 1));
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		pii best = cur;
		for (int i = 0; i < 4; i++) {
			pii step = mp(cur.x + DIR[i][0], cur.y + DIR[i][1]);

			if (!valid(step.x, step.y)) continue;

			if (vis[best].find(step) != vis[best].end()) {
				x = vis[best][step];
			} else {
				printf("1 %d %d %d %d\n", best.x, best.y, step.x, step.y);
				fflush(stdout);
				scanf("%d", &x);
				vis[best][step] = x;
				vis[step][best] = x ^ 1;
			}

			if (x == 0) {
				best = step;
			}
		}

		if (cur == best) {
			printf("2 %d %d\n", cur.x, cur.y);
			fflush(stdout);
			return 0;
		}

		q.push(best);
	}
}
