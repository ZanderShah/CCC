#include <bits/stdc++.h>
using namespace std;

long long n;

bool bruteForce(long long n)
{
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (long long i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

long long nextPrime(long long n)
{
	for (long long i = n; true; i++)
		if (bruteForce(i))
			return i;
}

int main()
{
	cin >> n;
	cout << nextPrime(n);

	return 0;
}