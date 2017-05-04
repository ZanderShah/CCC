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
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

int N, dp[2005];
set<string> dict;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		dict.insert(s);
	}
	for (int t = 0; t < 10; t++) {
		cin >> s;

		dp[0] = -1;
		for (int i = 1; i <= s.length(); i++) {
			dp[i] = 2005;
		}
		for (int i = 0; i < s.length(); i++) {
			for (int j = 1; j + i <= s.length(); j++) {
				if (dict.find(s.substr(i, j)) != dict.end()) {
					dp[i + j] = min(dp[i + j], dp[i] + 1);
				}
			}
		}
		cout << dp[s.length()] << endl;
	}
}
