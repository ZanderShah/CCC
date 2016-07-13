#include <bits/stdc++.h>
using namespace std;

int n, a = 0;

int main()
{
	cin >> n;

	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		a += x;
	}

	if (n == 1)
		cout << (a == 1 ? "YES" : "NO");
	else
		cout << (a == n - 1 ? "YES" : "NO");
	return 0;
}