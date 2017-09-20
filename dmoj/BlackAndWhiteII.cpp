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

struct Network {
	struct Edge {
		int dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {
		}
	};

	int N, src, sink;
	vector<int> last;
	vector<bool> vis;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), vis(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	int dfs (int curr, int flow) {
		vis[curr] = 1;

		if (curr == sink) {
			return flow;
		}

		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && !vis[e[i].dest]) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				if (res > 0) {
					e[i].cost -= res;
					e[i ^ 1].cost += res;
					return res;
				}
			}
		}
		return 0;
	}

	int getFlow () {
		int res = 0, curr;
		fill(vis.begin(), vis.end(), 0);
		while ((curr = dfs(src, 1 << 30)) > 0) {
			res += curr;
			fill(vis.begin(), vis.end(), 0);
		}
		return res;
	}
};

int M, N, src, sink, k, in[105][105], out[105][105];
string g[105];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> M >> N;

	k = -1;
	for (int i = 0; i < N; ++i) {
		cin >> g[i];
		for (int j = 0; j < M; ++j) {
			in[i][j] = ++k;
			out[i][j] = ++k;
		}
	}
	src = ++k;
	sink = ++k;

	Network nw(k + 1, src, sink);
	for (int i = 0; i < N; ++i) {
		if (g[i][0] == '.') {
			nw.addEdge(src, in[i][0], 1 << 30, 0);
		}
		if (g[i][M - 1] == '.') {
			nw.addEdge(out[i][M - 1], sink, 1 << 30, 0);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] == '#') {
				continue;
			}

			nw.addEdge(in[i][j], out[i][j], 1, 0);

			// Left
			if (j > 0 && g[(i + 1) % N][j - 1] == '.') {
				nw.addEdge(out[i][j], in[(i + 1) % N][j - 1], 1 << 30, 0);
			}
			// Right
			if (j + 1 < M && g[(i + 1) % N][j + 1] == '.') {
				nw.addEdge(out[i][j], in[(i + 1) % N][j + 1], 1 << 30, 0);
			}

			// Dont move
			if (g[(i + 1) % N][j] == '.') {
				nw.addEdge(out[i][j], in[(i + 1) % N][j], 1 << 30, 0);
			}
			// Down
			if (g[(i + 2) % N][j] == '.') {
				nw.addEdge(out[i][j], in[(i + 2) % N][j], 1 << 30, 0);
			}
		}
	}

	cout << nw.getFlow() << endl;
}
