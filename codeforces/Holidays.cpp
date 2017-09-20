#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	cout << (n > 5 ? (n - 5) / 7 * 2 + min((n - 5) % 7, 2) : 0);
	cout << " " << n / 7 * 2 + min(n % 7, 2);

	return 0;
}