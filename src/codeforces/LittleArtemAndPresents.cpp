#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	cout << n / 3 * 2 + (n % 3 ? 1 : 0);
	return 0;
}