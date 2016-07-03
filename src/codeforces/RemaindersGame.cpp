#include <bits/stdc++.h>
using namespace std;

int n, k;
long long v = 1, x;

long long gcd(long long a, long long b)
{
	if (!a)
		return b;
	return gcd(b % a, a);
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);  

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v = gcd(k, lcm(v, x));
	}

	cout << (v == k ? "Yes" : "No");
}