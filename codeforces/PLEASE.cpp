#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const int MOD = 1000000007;

int k;
ll n, v;

ll p(ll a, ll b)
{
	ll ret = 1;

	for (; b; b >>= 1)
	{
		if (b & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
	}

	return ret;
}

int main()
{
	cin >> k;
	n = 2;
	bool even = false;

	for (int i = 0; i < k; i++)
	{
		cin >> v;
		if (v % 2 == 0)
			even = true;
		n = p(n, v);
	}
	n = n * p(2, MOD - 2) % MOD;

	if (even)
		cout << (n + 1) * p(3, MOD - 2) % MOD;
	else
		cout << (n - 1) * p(3, MOD - 2) % MOD;
	cout << "/";
	cout << n;

	return 0;
}