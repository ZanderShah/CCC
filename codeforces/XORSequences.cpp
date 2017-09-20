#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
const ll MOD = 1000000007;
ll k, a[100], m[100][100], v[100][100], r[100][100];

int main()
{
	cin >> n;
	cin >> k;
	k--;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[i][i] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			ll x = a[i] ^ a[j];
			int b = 0;

			for (int e = 0; e < 63; e++)
				if (x >> e & 1)
					b++;

			if (b % 3 == 0)
			{
				v[i][j] = 1;
				v[j][i] = 1;
			}
		}

	for (int e = 0; e < 63; e++)
	{
		if (k >> e & 1)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					r[i][j] = 0;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					for (int p = 0; p < n; p++)
						r[i][j] = (r[i][j] + m[i][p] * v[p][j] % MOD) % MOD;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					m[i][j] = r[i][j];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				r[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int p = 0; p < n; p++)
					r[i][j] = (r[i][j] + v[i][p] * v[p][j] % MOD) % MOD;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				v[i][j] = r[i][j];
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = (ans + m[i][j]) % MOD;
	cout << ans;

	return 0;
}