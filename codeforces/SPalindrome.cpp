#include <bits/stdc++.h>
using namespace std;

string s;
string a = "AbdHIMOopqTUVvWwXxTY";
string b = "AdbHIMOoqpTUVvWwXxTY";

int main()
{
	cin >> s;

	for (int i = 0, x; i <= s.length() / 2; i++)
	{
		x = -1;
		for (int j = 0; j < 20; j++)
			if (s[i] == a[j])
				x = j;

		if (x == -1 || s[s.length() - 1 - i] != b[x])
		{
			cout << "NIE";
			return 0;
		}
	}

	cout << "TAK";
	return 0;
}