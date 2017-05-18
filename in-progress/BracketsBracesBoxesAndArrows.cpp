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

const int MAXN = 2e5 + 5;

int N, x[MAXN];
ll K, cost[5];
string s, lf = "([{<", rf = ")]}>";
stack<int> st;
umii match;
vector<int> poss[MAXN];

int main() {
	cin >> N >> K;
	cin >> cost[1] >> cost[2] >> cost[3];
	cin >> s;

	// Make bracket matching less cancer
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == lf[j]) {
				x[i] = -(j + 1);
			}
		}
		for (int j = 0; j < 4; j++) {
			if (s[i] == rf[j]) {
				x[i] = j + 1;
			}
		}
	}

	// Get all matching pairs
	for (int i = 0; i < N; i++) {
		if (x[i] < 0) {
			st.push(i);
			continue;
		}

		if (st.empty()) {
			cout << "impossible" << endl;
			return 0;
		}

		match[i] = st.top();
		st.pop();
	}
}
