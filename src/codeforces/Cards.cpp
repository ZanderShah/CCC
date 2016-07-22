#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > a;

int main()
{
	cin >> n;
	for (int i = 0, x; i < n; i++)	
	{
		cin >> x;
		a.push_back(make_pair(x, i + 1));
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n / 2; i++)
		cout << a[i].second << " " << a[n - 1 - i].second << endl;
}