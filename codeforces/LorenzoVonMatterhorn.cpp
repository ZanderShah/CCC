#include <bits/stdc++.h>
#define ll long long
using namespace std;

int q, c;
ll v, u, w, g, f;
unordered_map<ll, ll> m;

ll lca(ll a, ll b)
{
	while (a != b)
	{
		if (a > b)
			a /= 2;
		else
			b /= 2;
	}

	return a;
}

int main()
{
	cin >> q;

	for (int r = 0; r < q; r++)
	{
		cin >> c >> v >> u;
		g = lca(v, u);

		if (c == 1)
		{
			cin >> w;

			while (v != g)
			{
				m[v] += w;
				v /= 2;
			}

			while (u != g)
			{
				m[u] += w;
				u /= 2;
			}
		}
		else
		{	
			f = 0;

			while (v != g)
			{
				f += m[v];
				v /= 2;
			}

			while (u != g)
			{
				f += m[u];
				u /= 2;
			}

			cout << f << endl;
		}
	}

	return 0;
}