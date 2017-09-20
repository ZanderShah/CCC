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

struct State {
	int x, y, sum, cuts;
};

int R, C, sx, sy, gx = 100, gy = 100, vis[15][15][105];
char g[10][10], m = 0;
queue<State> q;

inline int dist(int x, int y) {
	return (sx - x) * (sx - x) + (sy - y) * (sy - y);
}
inline bool valid(int x, int y) {
	return 0 <= x && x < R && 0 <= y && y < C;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &g[i][j]);
			if (g[i][j] == 'X') {
				g[i][j] = '.';
				sx = i;
				sy = j;
			} else if (g[i][j] > '0') {
				m = max(m, g[i][j]);
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (g[i][j] == m && dist(i, j) < dist(gx, gy)) {
				gx = i;
				gy = j;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 105; k++) {
				vis[i][j][k] = 1 << 30;
			}
		}
	}

	q.push(State {sx, sy, 0, 0});

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, s = q.front().sum, c = q.front().cuts;
		q.pop();

		if (c > R * C || vis[x][y][c] <= s) continue;

		vis[x][y][c] = s;

		for (int d = 0; d < 4; d++) {
			int xx = x + DIR[d][0], yy = y + DIR[d][1];
			if (!valid(xx, yy)) continue;
			q.push(State {xx, yy, s + max(0, g[xx][yy] - '0'), c + (g[xx][yy] > '0' ? 1 : 0)});
		}
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		if (vis[gx][gy][i] < vis[gx][gy][ans]) {
			ans = i;
		}
	}

	printf("%d\n", ans - 1);
}
