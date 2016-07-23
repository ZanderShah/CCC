#include <bits/stdc++.h>
using namespace std;

const string KEY = "HAILHYDRA";

string s, a;
int N;
char m[26];
bool hail;
vector<int> hydra;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.length() - 8; i++)
	{
		hail = s[i] == s[i + 4] && s[i + 1] == s[i + 8];

		for (int j = 1; j <= 8; j++)
			if (j != 4 && s[i] == s[i + j])
				hail = false;

		if (hail)
			hydra.push_back(i);
	}

	if (hydra.size() == 0)
	{
		cout << "KeyNotFoundError";
		return 0;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;

		for (int j = 0; j < a.length(); j++)
			m[a[j] - 'A'] = j + 'A';

		for (int j = 0; j < hydra.size(); j++)
		{
			hail = true;
			for (int k = 0; k <= 8; k++)
				if (m[s[hydra[j] + k] - 'A'] != KEY[k])
					hail = false;

			if (hail)
			{
				for (int k = 0; k < s.length(); k++)
					cout << m[s[k] - 'A'];
				return 0;
			}
		}
	}

	cout << "KeyNotFoundError";
	return 0;
}