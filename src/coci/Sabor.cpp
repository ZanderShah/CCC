#include <bits/stdc++.h>
using namespace std;

int N, c[200001];
vector<int> adj[200001];

int dfs(int x, int t)
{
	c[x] = t;
	for (int i = 0; i < adj[x].size(); i++)
		if (!c[adj[x][i]])
			dfs(adj[x][i], t ^ 3);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0, P; i < 5; i++)
	{
		scanf("%d", &P);
		for (int j = 0, a, b; j < P; j++)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	for (int i = 1; i <= N; i++)
		if (!c[i])
			dfs(i, 1);
	for (int r = 0; r < 10; r++)
		for (int x = 1, f[3]; x <= N; x++)
		{
			f[1] = f[2] = 0;
			for (int i = 0; i < adj[x].size(); i++)
				f[c[adj[x][i]]]++;
			if (f[c[x]] >= 3)
				c[x] ^= 3;
		}
	for (int i = 1; i <= N; i++)
		printf("%c", c[i] == 1 ? 'A' : 'B');
}
