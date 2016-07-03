#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, c, d;

int main()
{
	cin >> n >> k;
	cin >> a >> b >> c >> d;

	if (n <= 4 || k <= n)
		cout << -1;
	else
	{
		cout << a << " " << c << " ";
		for (int i = 1; i <= n; i++)
			if (i != a && i != b && i != c && i != d)
				cout << i << " ";
		cout << d << " " << b << endl;

		cout << c << " " << a << " ";
		for (int i = 1; i <= n; i++)
			if (i != a && i != b && i != c && i != d)
				cout << i << " ";
		cout << b << " " << d;
	}

	return 0;
}