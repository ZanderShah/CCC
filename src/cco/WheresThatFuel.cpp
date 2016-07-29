#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int N, P;
vector<pair<int, int> > v;

int main()
{
	scanf("%d %d", &N, &P);
	int t = 0, p = 1;
	for (int i = 0, a, b; i < N; i++)
	{
		scanf("%d %d", &a, &b);

		if (i + 1 == P)
			t += a;
		else if (a >= b)
			v.pb(mp(b, a - b));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		if (v[i].first <= t)
		{
			t += v[i].second;
			p++;
		}

	printf("%d\n%d", t, p);
}