#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, m, k, rubles = -1;
vector<pair<int, int> > adj[100001];
bool f[100001];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0, u, v, l; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &l);
		adj[u].pb(mp(v, l));
		adj[v].pb(mp(u, l));
	}

	for (int i = 0, a; i < k; i++)
	{
		scanf("%d", &a);
		f[a] = true;
	}

	for (int i = 1; i <= n; i++)
		if (!f[i])
			for (int j = 0; j < adj[i].size(); j++)
				if (f[adj[i][j].first])
					rubles = rubles == -1 ? adj[i][j].second : min(rubles, adj[i][j].second);

	printf("%d", rubles);
}
