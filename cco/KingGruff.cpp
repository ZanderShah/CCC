#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

struct Edge
{
	int x, l, c;
};

int N, M, A, B, distA[100000], distB[100000], v, Q, low, up;
vector<Edge> adjA[100000], adjB[100000];
bool vis[100000];
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > all;

void dijkstras(int* dist, int source, vector<Edge>* adj)
{
	for (int i = 0; i < N; i++)
	{
		dist[i] = 1 << 29;
		vis[i] = false;
	}

	dist[source] = 0;
	vis[source] = true;
	pq.push(mp(0, source));

	while (!pq.empty())
	{
		v = pq.top().second;
		pq.pop();
		vis[v] = true;

		for (int u = 0; u < adj[v].size(); u++)
			if (!vis[adj[v][u].x] && dist[adj[v][u].x] > dist[v] + adj[v][u].l)
			{
				dist[adj[v][u].x] = dist[v] + adj[v][u].l;
				pq.push(mp(-dist[adj[v][u].x], adj[v][u].x));
			}
	}
}

int main()
{
	scanf("%d %d %d %d", &N, &M, &A, &B);
	A--;
	B--;

	for (int i = 0, x, y, l, c; i < M; i++)
	{
		scanf("%d %d %d %d", &x, &y, &c, &l);
		adjA[x - 1].pb(Edge { y - 1, c, l } );
		adjB[y - 1].pb(Edge { x - 1, c, l } );
	}

	dijkstras(distA, A, adjA);
	dijkstras(distB, B, adjB);

	all.pb(mp(0, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < adjA[i].size(); j++)
			all.pb(mp(distA[i] + adjA[i][j].l + distB[adjA[i][j].x], adjA[i][j].c));
	sort(all.begin(), all.end());

	for (int i = 1; i < all.size(); i++)
		all[i].second += all[i - 1].second;

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &v);
		low = 0;
		up = all.size() - 1;

		while (low <= up)
		{
			if (all[(low + up) / 2].first <= v)
				low = (low + up) / 2 + 1;
			else
				up = (low + up) / 2 - 1;
		}

		printf("%d\n", (all[up].first < (1 << 29) ? all[up].second : 0));
	}
}
