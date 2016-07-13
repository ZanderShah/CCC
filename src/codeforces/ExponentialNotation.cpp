#include <bits/stdc++.h>
using namespace std;

string s;
int i = 0, e = 100000001;
string a = "", b = "";

int main()
{
	cin >> s;

	while (s[i] == '0' || s[i] == '.')
		i++;	

	for (int j = 0; j < s.length(); j++)
		if (s[j] == '.')
			e = j - i;

	if (e > 0)
		e--;
	if (e == 100000000)
		e = s.length() - 1 - i;

	for (int j = i + 1; j < s.length(); j++)
		if (s[j] != '.')
			b += s[j];

	cout << s[i];

	i = b.length() - 1;
	while (i >= 0 && b[i] == '0')
		i--;

	if (i >= 0)
	{
		cout << '.';
		for (int j = 0; j <= i; j++)
			cout << b[j];
	}

	if (e)
		cout << "E" << e;

	return 0;
}