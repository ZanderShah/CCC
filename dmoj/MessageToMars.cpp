#include <bits/stdc++.h>
using namespace std;

int N, T[2001];
string a, b;
bitset<2001> adj[2001];

void Faliure() 
{
	T[0] = -1;
	for (int i = 0, j = -1; i < b.length(); i++, j++, T[i] = j) 
		while (j >= 0 && b[i] != b[j])
			j = T[j];
}

void KMP() 
{
	for (int i = 0, j = 0; i < a.length(); i++, j++)
	{
		while (j >= 0 && a[i] != b[j])
			j = T[j];
		if (j == b.length() - 1)
		{
			adj[i - j][i + 1] = 1;
			j = T[j];
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> b;
		Faliure();
		KMP();
	}

	int ans = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = i + 1; j < a.length(); j++)
			if (adj[i][j])
				adj[i] |= adj[j];
		ans += adj[i].count();
	}
	cout << ans;
}