#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1005;

int N, x, y;
vector<int> adj[MAXN];
bool vis[MAXN];

bool dfs(int x) {
	vis[x] = true;
	if (x == y)
		return true;
	bool ret = false;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]] && dfs(adj[x][i]))
			ret = true;
	return ret;
}

int main() {
	scan(N);
	for (int i = 0; i < N; i++) {
		scan(x);
		scan(y);
		adj[x].pb(y);
	}
	scan(x);
	scan(y);
	printf("%s", dfs(x) ? "Tangled" : "Not Tangled");
}
