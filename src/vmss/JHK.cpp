#include <bits/stdc++.h>
using namespace std;

bool sieve[7000];
int dp[7000];
vector<int> primes;
int n, k;

int main()
{
	cin >> n >> k;

	for (int i = 2; i <= n; i++)
		if (!sieve[i])
		{
			primes.push_back(i);
			for (int j = i; j <= n; j += i)
				sieve[j] = true;
		}

	for (int i = 0; i < primes.size(); i++)
		dp[primes[i]] = 1;

	int a = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < primes.size(); j++)
			if (i - primes[j] >= 1 && dp[i - primes[j]] >= 1)
				dp[i] = dp[i] == 0 ? dp[i - primes[j]] + 1 : min(dp[i], dp[i - primes[j]] + 1);
		if (dp[i] == k)
			a++;
	}	

	cout << a;
	return 0;
}