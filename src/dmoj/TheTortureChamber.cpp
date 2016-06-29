#include <bits/stdc++.h>
using namespace std;

bitset<1000000> sieve;
vector<int> primes;
int n, m, t;

int before(int n)
{
	int ret = 0;
	for (int i = 0; i < primes.size(); i++)
		if (primes[i] < n)
			ret++;
		else
			return ret;
	return ret;
}

int main()
{
	for (int i = 2; i < 1000000; i++)
		if (!sieve[i])
		{
			primes.push_back(i);
			for (int j = i; j < 1000000; j += i)
				sieve[j] = 1;
		}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int ans = before(m) - before(n);
		cout << max(ans, -ans) << endl;
	}

	return 0;
}#include <bits/stdc++.h>
using namespace std;

bitset<1000000> sieve;
vector<int> primes;
int n, m, t;

int before(int n)
{
	int ret = 0;
	for (int i = 0; i < primes.size(); i++)
		if (primes[i] < n)
			ret++;
		else
			return ret;
	return ret;
}

int main()
{
	for (int i = 2; i < 1000000; i++)
		if (!sieve[i])
		{
			primes.push_back(i);
			for (int j = i; j < 1000000; j += i)
				sieve[j] = 1;
		}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int ans = before(m) - before(n);
		cout << max(ans, -ans) << endl;
	}

	return 0;
}