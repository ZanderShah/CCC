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
#include <cassert>

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

int N, K, l, r;
string lf = "([{", rf = ")]}", s, orig;
stack<pii> st;
umii match;

int main() {
	cin >> N >> K;
	cin >> orig;
	s = orig;

	for (int i = 0; i < N; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(mp(s[i], i));
			continue;
		}

		// No match for right bracket
		if (st.empty()) {
			cout << "impossible" << endl;
			return 0;
		}

		char c = st.top().x;
		match[i] = st.top().y;
		st.pop();

		for (int j = 0; j < 3; j++) {
			if (lf[j] == c) {
				l = j;
			}
			if (rf[j] == s[i]) {
				r = j;
			}
		}

		if (l != r) {
			if (K == 0) {
				cout << "impossible" << endl;
				return 0;
			}
			K--;
			s[i] = rf[l];
		}
	}

	for (int i = 0; i < N; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			continue;
		}

		if (K >= 2) {
			for (int j = 0; j < 3; j++) {
				if (lf[j] == orig[match[i]]) {
					l = j;
				}
				if (rf[j] == orig[i]) {
					r = j;
				}
			}

			if (l == r) {
				s[match[i]] = lf[(l + 1) % 3];
				s[i] = rf[(r + 1) % 3];
				K -= 2;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			continue;
		}

		if (K >= 1) {
			for (int j = 0; j < 3; j++) {
				if (lf[j] == orig[match[i]]) {
					l = j;
				}
				if (rf[j] == orig[i]) {
					r = j;
				}
			}

			if (l != r) {
				// s[i] changed to match with s[match[i]]
				bool valid[3] = {1, 1, 1};
				for (int j = 0; j < 3; j++) {
					if (lf[j] == orig[match[i]] || rf[j] == orig[i]) {
						valid[j] = 0;
					}
				}
				for (int j = 0; j < 3; j++) {
					if (valid[j]) {
						s[match[i]] = lf[j];
						s[i] = rf[j];
					}
				}
				K--;
			}
		}
	}

	if (K != 0) {
		cout << "impossible" << endl;
		return 0;
	}

	cout << s << endl;
}
