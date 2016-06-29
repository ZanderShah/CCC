#include <bits/stdc++.h>
using namespace std;

int a, m;
bool v[100001];

int main()
{
	cin >> a >> m;

	while (a)
	{
		if (v[a])
		{
			cout << "No";
			return 0;
		}

		v[a] = true;
		a += a % m;
		a %= m;
	}

	cout << "Yes";
	return 0;
}