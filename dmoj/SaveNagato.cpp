#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int N, down[500001], up[500001], parent[500001];
vector<int> adj[500001];

int goDown(int x)
{
	int ret = 1;
	for (int i = 0; i < adj[x].size(); i++)
		if (adj[x][i] != parent[x])
		{
			parent[adj[x][i]] = x;
			ret = max(ret, 1 + goDown(adj[x][i]));
		}
	return down[x] = ret;
}

void goUp(int x)
{
	int a = 0, b = 0;

	for (int i = 0; i < adj[x].size(); i++)
		if (adj[x][i] != parent[x])
			if (down[adj[x][i]] > a)
			{
				b = a;
				a = down[adj[x][i]];
			}
			else if (down[adj[x][i]] > b)
			{
				b = down[adj[x][i]];
			}

	for (int i = 0; i < adj[x].size(); i++)
		if (adj[x][i] != parent[x])
		{
			up[adj[x][i]] = up[x] + 1;

			if (down[adj[x][i]] != a)
				up[adj[x][i]] = max(up[adj[x][i]], 2 + a);
			else if (b)
				up[adj[x][i]] = max(up[adj[x][i]], 2 + b);
			goUp(adj[x][i]);
		}
}

int main()
{
	scan(N);
	adj[0].push_back(1);
	for (int i = 0, a, b; i < N - 1; i++)
	{
		scan(a);
		scan(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	goDown(1);
	goUp(0);

	for (int i = 1; i <= N; i++)
		printf("%d\n", max(up[i], down[i]));
}
