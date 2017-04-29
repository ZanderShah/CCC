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

int k;
string s;

int length(int w, int i) {
	// Find best cut off point
	if (i + w >= s.length()) {
		return 1;
	}

	int j = i + w - 1;

	while (i <= j && s[j] != ' ' && s[j] != '-') {
		j--;
	}

	// Impossible to break here
	if (j < i) {
		return 1 << 30;
	}
	return length(w, j + 1) + 1;
}

int main() {
	cin >> k;
	getline(cin, s);
	getline(cin, s);

	int lo = 1, hi = s.length(), mid = (lo + hi) >> 1;
	while (lo <= hi) {
		if (length(mid, 0) <= k) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
		mid = (lo + hi) >> 1;
	}

	cout << lo << endl;
}
