#include <bits/stdc++.h>
using namespace std;

int n, m, r[1001], c[1001], t;
char g[1001][1001];

int main()
{
	cin >> n >> m;
	t = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> g[i];

		for (int j = 1; j <= m; j++)
		{
			if (g[i][j - 1] == '*')
			{
				r[i]++;
				c[j]++;
				t++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if ((r[i] + c[j] == t && g[i][j - 1] == '.') || (r[i] + c[j] == t + 1 && g[i][j - 1] == '*'))
			{
				cout << "YES" << endl;
				cout << i << " " << j;
				return 0;
			}
		}

	if (t == 0)
	{
		cout << "YES" << endl;
		cout << 1 << " " << 1;
	}
	else
		cout << "NO";

	return 0;
}