#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define mp make_pair
using namespace std;

int V, E, balloons[1001], x;
double dist[1001];
bool vis[1001];
vector<pair<int, double> > adj[1001];
priority_queue<pair<double, int> > pq;

// I really need to read the problem statements more carefully

int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0, m, n, d, s; i < E; i++)
	{
		scanf("%d %d %d %d", &m, &n, &d, &s);
		adj[m].pb(mp(n, d * 1.0 / s * 3600));
		adj[n].pb(mp(m, d * 1.0 / s * 3600));
	}

	for (int i = 2; i <= V; i++)
		dist[i] = 1 << 30;
	pq.push(mp(0, 1));

	while (!pq.empty())
	{
		x = pq.top().second;
		pq.pop();
		vis[x] = true;

		for (int i = 0; i < adj[x].size(); i++)
			if (!vis[adj[x][i].first])
			{
				if (dist[adj[x][i].first] >= dist[x] + adj[x][i].second)
				{
					dist[adj[x][i].first] = dist[x] + adj[x][i].second;
					balloons[adj[x][i].first] = balloons[x] + 1;
					pq.push(mp(-dist[adj[x][i].first], adj[x][i].first));
				}
				else if (dist[adj[x][i].first] == dist[x] + adj[x][i].second)
				{
					balloons[adj[x][i].first] = min(balloons[adj[x][i].first], balloons[x] + 1);
				}
			}
	}

	printf("%d\n%d", balloons[V], (int) round(dist[V] / 180));
}
