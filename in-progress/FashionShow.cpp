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

struct Edge {
	int dest, cost, next;
	Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {
	}
};

struct Network {
	int N, src, sink;
	vector<int> last, dist;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), dist(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = (int)e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = (int)e.size() - 1;
	}

	bool getPath () {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (int i = last[curr]; i != -1; i = e[i].next) {
				if (e[i].cost > 0 && dist[e[i].dest] == -1) {
					dist[e[i].dest] = dist[curr] + 1;
					q.push(e[i].dest);
				}
			}
		}

		return dist[sink] != -1;
	}

	int dfs (int curr, int flow) {
		if (curr == sink)
			return flow;
		int ret = 0;
		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && dist[e[i].dest] == dist[curr] + 1) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				ret += res;
				e[i].cost -= res;
				e[i ^ 1].cost += res;
				flow -= res;
				if (flow == 0)
					break;
			}
		}
		return ret;
	}

	int getFlow () {
		int res = 0;
		while (getPath())
			res += dfs(src, 1 << 30);
		return res;
	}
};

const char KEY[4] = {'$', '+', 'x', 'o'};
const int MAXN = 105;
const int BIGN = 100005;

int T, N, M, r, c, v, updates[MAXN][MAXN];
char x;
bool col[MAXN], row[MAXN], up[2 * MAXN], down[2 * MAXN];

int main() {
	// cin.tie(0);
	// ios_base::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				row[i] = col[j] = up[j - i + MAXN] = down[i + j] = 1;
			}
		}

		v = 0;
		for (int m = 0; m < M; m++) {
			cin >> x >> r >> c;
			if (x != 'x') {
				up[c - r + MAXN] = down[c + r] = 0;
				v++;
			}
			if (x != '+') {
				row[r] = col[c] = 0;
				v++;
			}
		}

		// Greedily place rooks
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (row[i] && col[j]) {
					updates[i][j] = 1;
					row[i] = col[j] = 0;
					v++;
				}
			}
		}

		// for (int i = 1; i <= N; i++) {
		//      // src to cols
		//      plusn.addEdge(0, i, 1, 1);
		//      // rows to sink
		//      plusn.addEdge(i * N, MAXN - 1, 1, 1);
		// }
		//
		// for (int i = 1; i <= N; i++) {
		//      for (int j = 1; j <= N; j++) {
		//              if (row[i] && col[j]) {
		//                      plusn.addEdge(i * N + j, j, 1, 1);
		//                      plusn.addEdge(i * N + j, i * N, 1, 1);
		//              }
		//              if (up[j - i + 105] && down[i + j]) {
		//                      // crossn.addEdge(0, i * N + j + 500, 1, 1);
		//                      // crossn.addEdge(i * N + j + 500, j - i + 105, 1, 1);
		//                      // crossn.addEdge(i * N + j + 500, j + i, 1, 1);
		//              }
		//      }
		// }
		//
		// cout << v << endl << plusn.getFlow() << endl << crossn.getFlow() << endl << endl;
	}
}
