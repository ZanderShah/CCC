#include <bits/stdc++.h>
using namespace std;

int A, N;
pair<char, char> e[26];
vector<int> m;
bool used[26];
string a, b;

bool valid(int v, int L)
{
	memset(used, false, sizeof used);
	for (int i = 0; i < L; i++)
		if (v & (1 << i))
		{
			if (used[e[i].first - 'a'])
				return false;
			used[e[i].first - 'a'] = true;
		}
		else
		{
			if (used[e[i].second - 'a'])
				return false;
			used[e[i].second - 'a'] = true;
		}
	return true;
}

bool mappable(int v)
{
	for (int i = 0; i < a.length(); i++)
		if (v & (1 << (a[i] - 'a')))
		{
			if (e[a[i] - 'a'].first != b[i])
				return false;
		}
		else
		{
			if (e[a[i] - 'a'].second != b[i])
				return false;
		}
	return true;
}

void compute(int i, int v)
{
	if (i == A)
		m.push_back(v);
	else
	{
		if (valid(v + (1 << i), i + 1))
			compute(i + 1, v + (1 << i));
		if (valid(v, i + 1))
			compute(i + 1, v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A;
	for (int i = 0; i < A; i++)
		cin >> e[i].first >> e[i].second;
	compute(0, 0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		bool yes = false;
		for (int i = 0; i < m.size() && !yes; i++)
			if (mappable(m[i]))
				yes = true;
		cout << (yes ? "YES" : "NO") << endl;
	}
}
