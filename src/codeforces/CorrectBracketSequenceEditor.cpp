#include <bits/stdc++.h>
using namespace std;

int n, m, p, pairs[500000], l[500000], r[500000];
string br, op;

int main()
{
	cin >> n >> m >> p;
	p--;
	cin >> br;
	cin >> op;
	
	stack<int> t;

	for (int i = 0; i < n; i++)
	{
		l[i] = i - 1;
		r[i] = (i + 1 < n ? i + 1 : -1);

		if (br[i] == '(')
			t.push(i);
		else
		{
			pairs[t.top()] = i;
			pairs[i] = t.top();
			t.pop();
		}
	}

	for (int i = 0, a, b; i < m; i++)
	{
		if (op[i] == 'L')
			p = l[p];
		else if (op[i] == 'R')
			p = r[p];
		else
		{
			a = min(p, pairs[p]);
			b = max(p, pairs[p]);

			if (l[a] != -1)
				r[l[a]] = r[b];
			if (r[b] != -1)
				l[r[b]] = l[a];

			if (r[b] != -1)
				p = r[b];
			else
				p = l[a];
		}
	}

	while (l[p] != -1)
		p = l[p];
	while (p != -1)
	{
		cout << br[p];
		p = r[p];
	}

	return 0;
}