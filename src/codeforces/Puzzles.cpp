#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x;
ll sz[100000];
vector<int> adj[100000];
double t[100000];

ll size(int x)
{
	if (adj[x].size() == 0)
		return sz[x] = 1;
	else
	{
		int ret = 1;
		for (int i = 0; i < adj[x].size(); i++)
			ret += size(adj[x][i]);
		return sz[x] = ret;
	}
}

void dfs(int x, int p)
{
	t[x] = t[p] + 1 + (sz[p] - 1 - sz[x]) / 2.0;

	for (int i = 0; i < adj[x].size(); i++)
		dfs(adj[x][i], x);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &x);
		adj[x - 1].push_back(i);
	}

	size(0);

	t[0] = 1;
	for (int i = 0; i < adj[0].size(); i++)
		dfs(adj[0][i], 0);

	for (int i = 0; i < n; i++)
		printf("%f ", t[i]);

	return 0;
}