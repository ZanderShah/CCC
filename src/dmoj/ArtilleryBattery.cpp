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
#include <cassert>

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

string s;
int x, y, g[15][15], E = 0, mostKills = 0, leastMoves = 0;
int vis[15][15][1 << 16];

void play(int r, int c, int k, int m) {
	if (vis[r][c][k] != -1 && vis[r][c][k] <= m) {
		return;
	}

	vis[r][c][k] = m;

	int kills = __builtin_popcount(k);
	if (kills > mostKills) {
		mostKills = kills;
		leastMoves = m;
	} else if (kills == mostKills) {
		leastMoves = min(leastMoves, m);
	}

	if (kills == E - 1) {
		return;
	}

	// Travel
	for (int i = r - 1; i >= 0; i--) {
		if (g[i][c] && !(g[i][c] & k)) {
			// Capture attempt
			for (int j = i - 1; j >= 0; j--) {
				if (g[j][c] && !(g[j][c] & k)) {
					play(j, c, k | g[j][c], m + 1);
					break;
				}
			}
			break;
		}
		play(i, c, k, m + 1);
	}
	for (int i = r + 1; i < 10; i++) {
		if (g[i][c] && !(g[i][c] & k)) {
			// Capture attempt
			for (int j = i + 1; j < 10; j++) {
				if (g[j][c] && !(g[j][c] & k)) {
					play(j, c, k | g[j][c], m + 1);
					break;
				}
			}
			break;
		}
		play(i, c, k, m + 1);
	}
	for (int i = c - 1; i >= 0; i--) {
		if (g[r][i] && !(g[r][i] & k)) {
			// Capture attempt
			for (int j = i - 1; j >= 0; j--) {
				if (g[r][j] && !(g[r][j] & k)) {
					play(r, j, k | g[r][j], m + 1);
					break;
				}
			}
			break;
		}
		play(r, i, k, m + 1);
	}
	for (int i = c + 1; i < 9; i++) {
		if (g[r][i] && !(g[r][i] & k)) {
			// Capture attempt
			for (int j = i + 1; j < 9; j++) {
				if (g[r][j] && !(g[r][j] & k)) {
					play(r, j, k | g[r][j], m + 1);
					break;
				}
			}
			break;
		}
		play(r, i, k, m + 1);
	}
}

struct State {
	int r, c, k, m;
};

int main() {
	memset(vis, -1, sizeof vis);

	for (int i = 0; i < 10; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			if (s[j] == 'C') {
				x = i;
				y = j;
			} else if (s[j] == 'E') {
				g[i][j] = 1 << E;
				E++;
			}
		}
	}

	queue<State> q;
	q.push(State {x, y, 0, 0});

	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, k = q.front().k, m = q.front().m;
		q.pop();

		if (vis[r][c][k] != -1 && vis[r][c][k] <= m) {
			continue;
		}

		vis[r][c][k] = m;

		int kills = __builtin_popcount(k);
		if (kills > mostKills) {
			mostKills = kills;
			leastMoves = m;
		} else if (kills == mostKills) {
			leastMoves = min(leastMoves, m);
		}

		if (kills == E - 1) {
			break;
		}

		// Travel
		for (int i = r - 1; i >= 0; i--) {
			if (g[i][c] && !(g[i][c] & k)) {
				// Capture attempt
				for (int j = i - 1; j >= 0; j--) {
					if (g[j][c] && !(g[j][c] & k)) {
						q.push(State {j, c, k | g[j][c], m + 1});
						break;
					}
				}
				break;
			}
			q.push(State {i, c, k, m + 1});
		}
		for (int i = r + 1; i < 10; i++) {
			if (g[i][c] && !(g[i][c] & k)) {
				// Capture attempt
				for (int j = i + 1; j < 10; j++) {
					if (g[j][c] && !(g[j][c] & k)) {
						q.push(State {j, c, k | g[j][c], m + 1});
						break;
					}
				}
				break;
			}
			q.push(State {i, c, k, m + 1});
		}
		for (int i = c - 1; i >= 0; i--) {
			if (g[r][i] && !(g[r][i] & k)) {
				// Capture attempt
				for (int j = i - 1; j >= 0; j--) {
					if (g[r][j] && !(g[r][j] & k)) {
						q.push(State {r, j, k | g[r][j], m + 1});
						break;
					}
				}
				break;
			}
			q.push(State {r, i, k, m + 1});
		}
		for (int i = c + 1; i < 9; i++) {
			if (g[r][i] && !(g[r][i] & k)) {
				// Capture attempt
				for (int j = i + 1; j < 9; j++) {
					if (g[r][j] && !(g[r][j] & k)) {
						q.push({r, j, k | g[r][j], m + 1});
						break;
					}
				}
				break;
			}
			q.push(State {r, i, k, m + 1});
		}
	}

	// play(x, y, 0, 0);

	printf("%d %d\n", mostKills, leastMoves);
}
