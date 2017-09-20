#include <bits/stdc++.h>
using namespace std;

int n, x[200000], c = -1;
string s;

int main()
{
	cin >> n;
	cin >> s;

	cin >> x[0];
	for (int i = 1; i < n; i++)
	{
		cin >> x[i];

		if (s[i - 1] == 'R' && s[i] == 'L')
		{
			if (c == -1)
				c = (x[i] - x[i - 1]) / 2;
			else
				c = min(c, (x[i] - x[i - 1]) / 2);
		}
	}

	cout << c;
	return 0;
}