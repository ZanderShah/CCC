#include <bits/stdc++.h>
using namespace std;

int n, m;
int node[1000000];
vector<int> adj[1000000], split[2];
bool contradiction;

void dfs(int i, int c)
{
	if (node[i] > 0)
	{
		if (node[i] != c)
			contradiction = true;
	}
	else
	{
		node[i] = c;

		for (int x = 0; x < adj[i].size(); x++)
			dfs(adj[i][x], c == 1 ? 2 : 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		if (!node[i])
			dfs(i, 1);

	if (contradiction)
		printf("-1");
	else
	{
		for (int i = 0; i < n; i++)
			split[node[i] - 1].push_back(i + 1);

		printf("%d\n", split[0].size());
		for (int i = 0; i < split[0].size(); i++)
			printf("%d ", split[0][i]);
		printf("\n%d\n", split[1].size());
		for (int i = 0; i < split[1].size(); i++)
			printf("%d ", split[1][i]);
	}

	return 0;
}