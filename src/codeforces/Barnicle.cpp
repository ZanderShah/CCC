#include <bits/stdc++.h>
using namespace std;

string s;
int p = 9001, e, l;
char x;
queue<char> front;
deque<char> back;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			p = i;
		else if (s[i] == 'e')
		{
			e = stoi(s.substr(i + 1));
			break;
		}
		else
		{
			if (i < p)
				front.push(s[i]);
			else
				back.push_back(s[i]);
		}
	}

	for (int i = 0; i < e; i++)
	{
		if (back.empty())
			x = '0';
		else
		{
			x = back.front();
			back.pop_front();
		}

		front.push(x);
	}

	while (front.front() == '0' && front.size() != 1)
		front.pop();
	while (!back.empty() && back.back() == '0')
		back.pop_back();

	while (!front.empty())
	{
		cout << front.front();
		front.pop();
	}

	if (!back.empty())
		cout << ".";

	while (!back.empty())
	{
		cout << back.front();
		back.pop_front();
	}

	return 0;
}