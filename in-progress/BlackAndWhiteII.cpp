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

int M, N, src, sink;
char g[105][105];
unordered_map<int, unordered_map<int, int> > trans;

int main() {
	scanf("%d %d", &M, &N);

	src = 0;
	sink = 1;

	Network nw(N * M + 5, src, sink);

	for (int i = 0, k = 2; i < N; i++) {
		for (int j = 0; j < M; j++, k++) {
			trans[i][j] = k;
		}
	}

	for (int i = 0; i < N; i++) {
		scanf(" %s", g[i]);
		for (int j = 0; j < M; j++) {
			if (g[i][j] == '#') {
				continue;
			}
			// Left
			if (j > 0 && g[(i + 1) % N][j - 1] == '.') {
				nw.addEdge(trans[i][j], trans[(i + 1) % N][j - 1], 1 << 30, 0);
			}
			// Right
			if (j + 1 < M && g[(i + 1) % N][j + 1] == '.') {
				nw.addEdge(trans[i][j], trans[(i + 1) % N][j + 1], 1 << 30, 0);
			}

			// Up
			if (g[(i + 1) % N][j] == '.') {
				nw.addEdge(trans[i][j], trans[(i + 1) % N][j], 1 << 30, 0);
			}
			// Down
			if (g[(i + 2) % N][j] == '.') {
				nw.addEdge(trans[i][j], trans[(i + 2) % N][j], 1 << 30, 0);
			}
		}

		if (g[i][0] == '.') {
			nw.addEdge(src, trans[i][0], 1 << 30, 0);
		}
		if (g[i][M - 1] == '.') {
			nw.addEdge(trans[i][M - 1], sink, 1 << 30, 0);
		}
	}

	printf("%d\n", nw.getFlow());
}
