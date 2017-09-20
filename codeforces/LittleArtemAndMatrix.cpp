#include <bits/stdc++.h>
using namespace std;

int n, m, q, t[100][100];
long long pairs[10000];
unordered_set<int> used;

int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			t[i][j] = i * m + j;
			pairs[i * m + j] = 1e10;
		}


	for (int i = 0, c, x, y, z; i < q; i++)
	{
		cin >> c;

		if (c == 2)
		{
			cin >> x;
			x--;
			y = t[0][x];
			for (int i = 1; i < n; i++)
				t[i - 1][x] = t[i][x];
			t[n - 1][x] = y;
		}
		else if (c == 1)
		{
			cin >> x;
			x--;
			y = t[x][0];
			for (int i = 1; i < m; i++)
				t[x][i - 1] = t[x][i];
			t[x][m - 1] = y;
		}
		else
		{
			cin >> x >> y >> z;
			x--;
			y--;
			pairs[t[x][y]] = z;
			used.insert(z);
		}
	}

	int f = -1e9;
	while (used.find(f) != used.end())
		f++;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pairs[i * m + j] != 1e10)
				cout << pairs[i * m + j] << " ";
			else
				cout << f << " ";
		}
		cout << endl;
	}

	return 0;
}