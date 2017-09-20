#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, d;
long long t = 0;
map<int, vector<int> > x, y;
set<int> xTag, yTag;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		x[a].push_back(b);
		y[b].push_back(a);
		xTag.insert(a);
		yTag.insert(b);
	}
	for (auto it = xTag.begin(); it != xTag.end(); it++)
	{
		sort(x[*it].begin(), x[*it].end());
	}
	for (auto it = yTag.begin(); it != yTag.end(); it++)
	{
		sort(y[*it].begin(), y[*it].end());
	}

	scanf("%d", &M);
	scanf("%d %d", &a, &b);
	for (int i = 1; i < M; i++)
	{
		scanf("%d %d", &c, &d);
		if (a == c && x[a].size())
		{
			auto low = lower_bound(x[a].begin(), x[a].end(), min(b, d));
			auto high = upper_bound(x[a].begin(), x[a].end(), max(b, d));
			//cout << (low - x[a].begin()) << "->" << (high - x[a].begin()) << endl;
			t += (high - x[a].begin()) - (low - x[a].begin());
		}
		else if (y[b].size())
		{
			auto low = lower_bound(y[b].begin(), y[b].end(), min(a, c));
			auto high = upper_bound(y[b].begin(), y[b].end(), max(a, c));
			//cout << (low - y[b].begin()) << "->" << (high - y[b].begin()) << endl;
			t += (high - y[b].begin()) - (low - y[b].begin());
		}
		a = c;
		b = d;
	}
	printf("%lld", t);
}