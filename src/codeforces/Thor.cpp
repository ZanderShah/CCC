#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, q, unread, notifs, lastChecked;
queue<int> a[300005];
vector<int> t;

void clear(queue<int> &q )
{
	queue<int> empty;
	swap( q, empty );
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0, x, v; i < q; i++)
	{
		scanf("%d %d", &x, &v);
		if (x == 1)
		{
			a[v].push(notifs);
			notifs++;
			unread++;
			t.pb(v);
		}
		else if (x == 2)
		{
			unread -= a[v].size();
			clear(a[v]);
		}
		else
		{
			for (int j = lastChecked; j < v; j++)
				while (!a[t[j]].empty() && a[t[j]].front() == j)
				{
					a[t[j]].pop();
					unread--;
				}
			lastChecked = max(lastChecked, v);
		}
		printf("%d\n", unread);
	}
}
