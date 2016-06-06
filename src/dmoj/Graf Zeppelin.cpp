#include <bits/stdc++.h>

using namespace std;

bitset<1501> adj[1501], total[1501], curAdj[1501];

int main() {
	int n, m, k, a, b;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a][b] = total[a][b] = curAdj[a][b] = adj[b][a] = total[b][a] =
				curAdj[b][a] = 1;
	}

	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= n; j++)
			for (int p = 1; p <= n; p++)
				if (curAdj[j][p])
					total[j] |= adj[p];

		for (int j = 1; j <= n; j++)
			curAdj[j] |= total[j];
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", total[i].count() + (total[i][i] ? 0 : 1));

	return 0;
}
