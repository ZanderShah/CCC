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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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

const int MAXN = 1e5 + 5;

int N, M, K, ans[MAXN], c, vis[MAXN];
vector<int> adj[MAXN];
pair<char, int> q[MAXN];
bool flip, b[5005];
priority_queue<short> pq;

void dfs(int i) {
	if (vis[i])
		return;
	vis[i] = 1;

	bool reset = 0;

	if (q[i].x == 'F' && !(b[q[i].y - 1] ^ flip)) {
		reset = 1;
		c++;
		b[q[i].y - 1] ^= 1;
	} else if ((q[i].x == 'D' && b[q[i].y - 1] ^ flip)) {
		reset = 1;
		c--;
		b[q[i].y - 1] ^= 1;
	} else if (q[i].x == 'X') {
		c = N - c;
		flip ^= 1;
	}

	ans[i] = c;

	for (int j = 0; j < adj[i].size(); j++)
		dfs(adj[i][j]);

	if (reset) {
		c += b[q[i].y - 1] ^ flip ? -1 : 1;
		b[q[i].y - 1] ^= 1;
	} else if (q[i].x == 'X') {
		c = N - c;
		flip ^= 1;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= M; i++) {
		scanf(" %c", &q[i].x);
		if (q[i].x != 'X')
			scanf("%d", &q[i].y);
		if (q[i].x == 'R')
			adj[q[i].y].pb(i);
		else
			adj[i - 1].pb(i);
	}

	dfs(0);

	for (int i = 0; i <= N; i++)
		vis[i] = 0;

	for (int i = 1; i <= M; i++) {
		vis[ans[i]]++;
		pq.push(ans[i]);

		while (!vis[pq.top()])
			pq.pop();

		printf("%d %d\n", ans[i], pq.top());

		if (i >= K - 1)
			vis[ans[i - K + 1]]--;
	}
}
