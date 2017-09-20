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

const ull MOD = 1e9 + 7;

int K, M, k, b = 0;
char c;

ull p(ull b, ull e) {
	ull ret = 1;
	for (int i = 0; i < 30; i++) {
		if (e >> i & 1) {
			ret = ret * b % MOD;
		}
		b = b * b % MOD;
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> K >> M;

	k = 1 << K;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cin >> c;
			b += c == '#';
		}
	}

	if (b == 0) {
		cout << 1 << endl;
		return 0;
	}


	ull t = 2;
	while (M > 10) {
		t = p(t, p(4, 10));
		M -= 10;
	}

	for (int i = 1; i <= M; i++) {
		t = p(t, 4);
	}

	cout << p((t + MOD - 1) % MOD, b) << endl;
}
