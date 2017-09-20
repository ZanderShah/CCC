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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
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
typedef unordered_map<int, int> umii;

struct cmp {
	bool operator() (const string& a, const string& b) const {
		if (a.length() != b.length()) {
			return a.length() < b.length();
		}
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				return a[i] < b[i];
			}
		}
		return 0;
	}
};

int N;
string s;
vector<string> ss;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i  = 0; i < N; i++) {
		cin >> s;
		ss.pb(s);
	}
	sort(ss.begin(), ss.end(), cmp());
	for (int i = 0; i < N; i++) {
		cout << ss[i] << endl;
	}
}
