#include <bits/stdc++.h>
using namespace std;

int N, M, size[400000], depth[400000], c, ed, best;
vector<int> adj[400000];
bool vis[400000];
long long total = 0;

void dfs(int x, int l)
{
	vis[x] = true;

	if (l > best)
	{
		best = l;
		ed = x;
	}

	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]])
			dfs(adj[x][i], l + 1);
}

void count(int x)
{
	vis[x] = true;
	// Through non-visited
	// Length of path is two depths + 1
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]])
		{
			count(adj[x][i]);
			if (depth[x] + depth[adj[x][i]] + 1 == best)
				total += size[x] * size[adj[x][i]];
			if (depth[adj[x][i]] + 1 > depth[x])
			{
				depth[x] = depth[adj[x][i]] + 1;
				size[x] = size[adj[x][i]];
			}
			else if (depth[adj[x][i]] + 1 == depth[x])
				size[x] += size[adj[x][i]];
		}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		size[i] = 1;
	for (int i = 0, a, b; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	dfs(0, 0);
	memset(vis, false, sizeof vis);
	dfs(ed, 0);
	memset(vis, false, sizeof vis);
	count(ed);
	cout << best + 1 << " " << total;
}
