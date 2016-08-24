#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

// Incomplete

const long long MOD = 1610612741, BASE = 137, DIV_MOD = 1269680117;

int N;
long long H[5000], B[5000], ans, x, y;
string s;
set<long long> vis;

inline long long hashy(int l, int r)
{
	return (H[r] - H[l - 1] * B[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	s = "$" + s;

	B[0] = 1;
	for (int i = 1; i <= s.length(); i++)
	{
		B[i] = B[i - 1] * BASE % MOD;
		H[i] = (H[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
	}

	// Gaps
	for (int i = 1; i < s.length(); i++)
	{
		// Leftmost and rightmost spot in string
		for (int l = 1, r = i + 1; r <= s.length(); l++, r++)
		{
			x = y = hashy(l, r);

			if (vis.find(x) == vis.end())
			{
				vis.insert(x);

				for (int j = 0; j < r - l; j++)
				{
					// Shift right by one
					y = (y - (s[r - j] - 'a' + 1)) * DIV_MOD % MOD;
					// Add missing letter
					y = (y + (s[r - j] - 'a' + 1) * B[r - l]) % MOD;

					if (x == y)
					{
						ans++;
						break;
					}
				}
			}
		}
	}

	cout << ans;
}
