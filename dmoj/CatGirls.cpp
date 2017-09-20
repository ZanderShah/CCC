#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, p, c, low, up;
ll W;
vector<ll> cute, weight, dp;
char d;

int main()
{
	ios_base::sync_with_stdio(false);   
	cin.tie(NULL);

	cin >> N >> W;
	
	cute.push_back(0);
	weight.push_back(0);
	dp.push_back(0);

	for (int i = 0, g = 0; i < N; i++)
	{
		cin >> d;

		if (d == 'A')
		{
			cin >> p >> c;

			weight.push_back(weight[g] + p);
			cute.push_back(cute[g] + c);

			g++;
			low = 0;
			up = g;

			while (low < up)
			{
				if (weight[g] - weight[(low + up) / 2] <= W)
					up = (low + up) / 2;
				else
					low = (low + up) / 2 + 1;
			}

			dp.push_back(max(dp[g - 1], cute[g] - cute[low]));
			cout << dp[g] << endl;
		}
		else
		{
			cute.pop_back();
			weight.pop_back();
			dp.pop_back();

			g--;
		}
	}
}