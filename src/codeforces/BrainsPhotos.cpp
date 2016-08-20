#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, m;
bool g;
char c;

int main()
{
	cin >> n >> m;
	g = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'C' || c == 'M' || c == 'Y')
				g = false;
		}
	cout << (g ? "#Black&White" : "#Color");
}
