#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <unordered_map>
#include <map>
#include <bitset>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef unordered_map<int, int> umii;

struct Snowflake {
	int snow[6];
	bool operator <(const Snowflake& s) const {
		for (int i = 0; i < 6; i++)
			if (snow[i] != s.snow[i])
				return snow[i] < s.snow[i];
		return 0;
	}
	bool operator ==(const Snowflake& s) const {
		for (int i = 0; i < 6; i++)
			if (snow[i] != s.snow[i])
				return 0;
		return 1;
	}
};

int n, arm[6], tiny;
Snowflake flake, t;
vector<Snowflake> snow;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		tiny = flake.snow[0] = 1e7 + 1;

		for (int j = 0; j < 6; j++) {
			scanf("%d", &arm[j]);
			if (arm[j] < tiny)
				tiny = arm[j];
		}

		for (int j = 0; j < 6; j++)
			if (arm[j] == tiny)
				for (int d = -1; d <= 1; d += 2) {
					for (int k = 0; k < 6; k++)
						t.snow[k] = arm[(j + d * k + 6) % 6];
					if (t < flake)
						flake = t;
				}

		snow.pb(flake);
	}

	sort(snow.begin(), snow.end());

	for (int i = 1; i < snow.size(); i++)
		if (snow[i - 1] == snow[i]) {
			printf("Twin snowflakes found.\n");
			return 0;
		}

	printf("No two snowflakes are alike.\n");
}
