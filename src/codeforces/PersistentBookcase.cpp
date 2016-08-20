#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

struct Query
{
	int c, i, j;
} q[100001];

int n, m, r, ans[100001], row[1001], c;
vector<int> adj[100001];
bool vis[100001], flip[1001], b[1001][1001];

void dfs(int x)
{
	if (vis[x])
		return;
	vis[x] = true;

	bool reset = false;

	if (q[x].c == 1 && !(b[q[x].i][q[x].j] ^ flip[q[x].i]))
	{
		c++;
		row[q[x].i]++;
		b[q[x].i][q[x].j] ^= 1;
		reset = true;
	}
	else if (q[x].c == 2 && (b[q[x].i][q[x].j] ^ flip[q[x].i]))
	{
		c--;
		row[q[x].i]--;
		b[q[x].i][q[x].j] ^= 1;
		reset = true;
	}
	else if (q[x].c == 3)
	{
		c -= row[q[x].i];
		row[q[x].i] = m - row[q[x].i];
		c += row[q[x].i];
		flip[q[x].i] ^= 1;
	}

	ans[x] = c;

	for (int i = 0; i < adj[x].size(); i++)
		dfs(adj[x][i]);

	if (reset)
	{
		c += b[q[x].i][q[x].j] ^ flip[q[x].i] ? -1 : 1;
		row[q[x].i] += b[q[x].i][q[x].j] ^ flip[q[x].i] ? -1 : 1;
		b[q[x].i][q[x].j] ^= 1;
	}
	else if (q[x].c == 3)
	{
		c -= row[q[x].i];
		row[q[x].i] = m - row[q[x].i];
		c += row[q[x].i];
		flip[q[x].i] ^= 1;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 1; i <= r; i++)
	{
		scanf("%d %d", &q[i].c, &q[i].i);
		if (q[i].c == 4)
			adj[q[i].i].pb(i);
		else
		{
			if (q[i].c == 1 || q[i].c == 2)
				scanf("%d", &q[i].j);
			adj[i - 1].pb(i);
		}
	}

	dfs(0);

	for (int i = 1; i <= r; i++)
		printf("%d\n", ans[i]);
}
