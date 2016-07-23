#include <bits/stdc++.h>
using namespace std;

int N;
string s;
unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int> > > > dp;

int go(int i, int a, int b, int c)
{
	if (dp.find(i) != dp.end() && dp[i].find(a) != dp[i].end() && dp[i][a].find(b) != dp[i][a].end() && dp[i][a][b].find(c) != dp[i][a][b].end())
		return dp[i][a][b][c];

	// Thanks to Jim for the help on stream :)
	// I tried to make the hashing less sketchy but it ended up way sketchier :P
	int ret = 0;

	if (i == N)
	{
		if (a <= b && a <= c)
			ret |= 1;
		if (b <= a && b <= c)
			ret |= 2;
		if (c <= a && c <= b)
			ret |= 4;
	}
	else if (s[i] == '~')
	{
		if (a <= b && a <= c)
			ret |= go(i + 1, a + 1, b, c);
		if (b <= a && b <= c)
			ret |= go(i + 1, a, b + 1, c);
		if (c <= a && c <= b)
			ret |= go(i + 1, a, b, c + 1);
	}
	else
	{
		if (s[i] == '1')
			ret |= go(i + 1, a + 1, b, c);
		else if (s[i] == '2')
			ret |= go(i + 1, a, b + 1, c);
		else
			ret |= go(i + 1, a, b, c + 1);
	}

	return dp[i][a][b][c] = ret;
}

int main()
{
	cin >> N;
	cin >> s;

	int ans = go(0, 0, 0, 0);

	if (ans & 1)
		cout << 1 << endl;
	if (ans & 2)
		cout << 2 << endl;
	if (ans & 4)
		cout << 3 << endl;
}