#include <bits/stdc++.h>
using namespace std;

struct State
{
	int x, y, z, d;
};

int W, L, H, N, g[101][101][101];
queue<State> q;

int end()
{
	int ret = 1 << 30;
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			if (g[W - i][L][H - j] >= 0)
				ret = min(ret, g[W - i][L][H - j]);
	return ret;
}

int main()
{
	scanf("%d %d %d", &W, &L, &H);
	scanf("%d", &N);

	for (int i = 1; i <= W; i++)
		for (int j = 1; j <= L; j++)
			for (int k = 1; k <= H; k++)
				g[i][j][k] = 1 << 30;

	for (int i = 0, x, y, z; i < N; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		g[x][y][z] = -1;
	}

	q.push(State { 1, 1, 1, 0 } );
	while (!q.empty())
	{
		int x = q.front().x, y = q.front().y, z = q.front().z, d = q.front().d;
		q.pop();

		if (g[x][y][z] > d)
		{
			g[x][y][z] = d;

			if (x - 1 >= 1 && x - 1 <= W && g[x - 1][y][z] > d + 1)
				q.push(State { x - 1, y, z, d + 1 } );
			if (x + 1 >= 1 && x + 1 <= W && g[x + 1][y][z] > d + 1)
				q.push(State { x + 1, y, z, d + 1 } );
			if (y - 1 >= 1 && y - 1 <= L && g[x][y - 1][z] > d + 1)
				q.push(State { x, y - 1, z, d + 1 } );
			if (y + 1 >= 1 && y + 1 <= L && g[x][y + 1][z] > d + 1)
				q.push(State { x, y + 1, z, d + 1 } );
			if (z - 1 >= 1 && z - 1 <= H && g[x][y][z - 1] > d + 1)
				q.push(State { x, y, z - 1, d + 1 } );
			if (z + 1 >= 1 && z + 1 <= H && g[x][y][z + 1] > d + 1)
				q.push(State { x, y, z + 1, d + 1 } );
		}
	}
	printf("%d", end());
}
