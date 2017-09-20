#include <bits/stdc++.h>
using namespace std;

int k, c, freq[26];
string s;

int main()
{
	cin >> k;
	cin >> s;
	for (int i = 0, x; i < s.length(); i++)
	{
		cout << (char) ((s[i] - 'a' + (i >= k ? c + 1 : 0)) % 26 + 'a');

		freq[s[i] - 'a']++;
		if (i >= k)
			freq[s[i - k] - 'a']--;
		c = 0;
		for (int j = 0; j < 26; j++)
			if (freq[j] > freq[c])
				c = j;
	}
}
