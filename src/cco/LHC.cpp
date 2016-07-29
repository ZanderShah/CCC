#include <bits/stdc++.h>
using namespace std;

int N, M, size[400000], c;
pair<long long, long long> lengths[400000];
vector<int> adj[400000];
bool vis[400000];

int dfs(int x)
{
	vis[x] = true;
	int ret = 1;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]])
			ret += dfs(adj[x][i]);
	return size[x] = ret;
}

int centroid(int x)
{
	vis[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]] && size[adj[x][i]] * 2 >= N)
			return centroid(adj[x][i]);
	return x;
}

void depth(int x, int p, int d)
{
	vis[x] = true;
	bool end = true;

	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]])
		{
			end = false;
			depth(adj[x][i], p, d + 1);
		}

	if (end)
	{
		if (d > lengths[p].first)
		{
			lengths[p].first = d;
			lengths[p].second = 1;
		}
		else if (d == lengths[p].first)
			lengths[p].second++;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0, a, b; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	dfs(0);

	memset(vis, false, sizeof vis);
	c = centroid(0);

	memset(vis, false, sizeof vis);
	vis[c] = true;
	for (int i = 0; i < adj[c].size(); i++)
		depth(adj[c][i], adj[c][i], 1);
	sort(lengths, lengths + N);

	printf("%lld ", lengths[N - 1].first + lengths[N - 2].first + 1);

	long long ans = 0, total = lengths[N - 1].second;
	bool same = (lengths[N - 1].first == lengths[N - 2].first);
	for (int i = N - 2; lengths[i].first == lengths[N - 2].first; i--)
	{
		ans += total * lengths[i].second;
		total += (same ? lengths[i].second : 0);
	}

	printf("%lld", ans);
}