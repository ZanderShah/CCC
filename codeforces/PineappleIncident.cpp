#include <bits/stdc++.h>
using namespace std;

int t, x, s;

int main()
{
	cin >> t >> s >> x;

	if (t == x)
	{
		cout << "YES";
	}
	else
	{
		for (int i = t + s; i <= x; i += s)
			if (i == x || i + 1 == x)
			{
				cout << "YES";
				return 0;
			}
		cout << "NO";
	}
}