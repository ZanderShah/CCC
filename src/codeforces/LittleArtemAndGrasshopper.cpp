#include <bits/stdc++.h>
using namespace std;

int n, d[100000];
bool v[100000];
string s;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> d[i];

	for (int i = 0; i < n && i >= 0; )
	{
		if (v[i])
		{
			cout << "INFINITE";
			return 0;
		}

		v[i] = true;

		if (s[i] == '>')
			i += d[i];
		else
			i -= d[i];
	}

	cout << "FINITE";
	return 0;
}