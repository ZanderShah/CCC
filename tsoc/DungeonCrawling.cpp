#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int N, M, dist[200000];
vector<int> adj[200000];
bool e[200000], d[20000];
long long seen[200000];
vector<int> ans;

int dfs(int x, int d)
{
	dist[x] = min(dist[x], d);
	seen[x]++;
	for (int i = 0; i < adj[x].size(); i++)
		dfs(adj[x][i], d + 1);
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		e[i] = d[i] = true;
		seen[i] = 0;
		dist[i] = MOD + 1;
	}
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		e[b] = false;
		d[a] = false;
	}

	for (int i = 0; i < N; i++)
		if (e[i])
			dfs(i, 1);

	long long total = 0;
	for (int i = 0; i < N; i++)
		if (d[i])
		{
			total = total + seen[i] % MOD;
			ans.push_back(dist[i]);
		}

	printf("%lld\n", total);
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}
