#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
int n;
string s, a;
vector<string> v;

int main()
{
	cin >> n;
	for (int i = 0, x; i < n; i++)
	{
		cin >> s;
		if (s == "insert")
		{
			cin >> x;
			a = to_string(x);
			pq.push(-x);
			v.push_back("insert " + a);
		}
		else if (s == "getMin")
		{
			cin >> x;
			a = to_string(x);
			while (!pq.empty() && pq.top() > -x)
			{			
				pq.pop();
				v.push_back("removeMin");
			}

			if (pq.empty() || pq.top() != -x)
			{
				pq.push(-x);
				v.push_back("insert " + a);
			}

			v.push_back("getMin " + a);
		}
		else 
		{
			if (pq.empty())
				v.push_back("insert 0");
			else
				pq.pop();

			v.push_back("removeMin");
		}
	}

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());
	
	return 0;
}
