#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
bool a[26];
string s;

int main()
{
	cin >> n;
	cin >> s;
	memset(a, false, sizeof a);

	if (n > 26)
		cout << -1;
	else
	{
		for (int i = 0; i < n; i++)
			if (!a[s[i] - 'a'])
				a[s[i] - 'a'] = true;
			else
				ans++;
		cout << ans;
	}

	return 0;
}