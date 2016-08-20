#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

long long n;

int main()
{
	cin >> n;

	if (n <= 2)
		cout << -1;
	else if (n % 2)
		cout << (n - 1) * (n + 1) / 2 << " " << (n * n + 1) / 2;
	else
		cout << n * n / 4 - 1 << " " <<  n * n / 4 + 1;
}
