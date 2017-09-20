#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if (!a)
		return b;
	return gcd(b % a, a);
}

long long n, a, b, p, q;

int main()
{
	cin >> n >> a >> b >> p >> q;
	cout << n / a * p + n / b * q - n / (a * b / gcd(a, b)) * min(p, q);
}