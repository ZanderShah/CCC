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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

const double PI = 3.14159265358979323846;
const int MAXN = 1e5 + 5;

struct Node {
	double A[3][3];
} n[MAXN];

int N, M, x, y, d, e, depth[MAXN], size[MAXN];
char c;
vector<int> adj[MAXN];
bool vis[MAXN];

Node multiply(Node a, Node b) {
	Node ret = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ret.A[i][j] += a.A[i][k] * b.A[k][j];
			}
		}
	}
	return ret;
}

int dfs(int x, int l) {
	vis[x] = 1;
	depth[x] = l;
	int ret = 0;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!vis[adj[x][i]]) {
			ret += dfs(adj[x][i], l + 1);
		}
	}
	return size[x] = ret;
}

void updateNode(int i) {
	for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++)
			n[i].A[j][k] = 0;
	scanf("%c ", &c);
	if (c == 'R') {
		scanf("%d", &x);
		n[i].A[0][0] = cos(x * 180 / PI);
		n[i].A[0][1] = -sin(x * 180 / PI);
		n[i].A[1][0] = sin(x * 180 / PI);
		n[i].A[1][1] = cos(x * 180 / PI);
	} else if (c == 'T') {
		scanf("%d %d", &x, &y);
		n[i].A[0][0] = n[i].A[1][1] = n[i].A[2][2] = 1;
		n[i].A[0][2] = x;
		n[i].A[1][2] = y;
	} else {
		scanf("%d %d %d", &x, &y, &d);
		n[i].A[0][0] = n[i].A[1][1] = d / 100.0;
		n[i].A[2][2] = 1;
		n[i].A[0][2] = x * (1 - d / 100.0);
		n[i].A[1][2] = y * (1 - d / 100.0);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		updateNode(i);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 0);
	for (int i = 0; i < M; i++) {
		scanf("%c ", &c);
		if (c == 'U') {
			scanf("%d", &x);
			updateNode(x);
		} else {
			scanf("%d %d %d %d", &x, &y, &d, &e);
		}
	}
}
