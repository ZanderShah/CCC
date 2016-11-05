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

const int A[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

ll N;

ll mmod(ll a, ll b, ll m) {
	ll x = 0, y = a % m;
	for (int i = 0; i < 63; i++, y = y * 2 % m)
		if (b >> i & 1)
			x = (x + y) % m;
	return x;
}

ll bpow(ll a, ll b, ll m) {
	ll ret = 1;
	for (int i = 0; i < 63; i++, a = mmod(a, a, m))
		if (b >> i & 1)
			ret = mmod(ret, a, m);
	return ret;
}

bool isPrime(ll n) {
	int r = 0;
	ll d = n - 1;
	while (d % 2 == 0) {
		d /= 2;
		r++;
	}

	for (int i = 0; i < 9 && A[i] <= n - 2; i++) {
		ll v = bpow(A[i], d, n);

		if (v == 1 || v == n - 1)
			continue;

		for (int j = 0; j < r - 1; j++) {
			v = mmod(v, v, n);

			if (v == 1)
				return 0;
			else if (v == n - 1)
				break;
		}

		if (v == n - 1)
			continue;

		return 0;
	}

	return 1;
}

int main() {
	cin >> N;
	if (N == 1 || N == 2) {
		cout << 2;
		return 0;
	}
	N += 1 - N % 2;
	while (!isPrime(N))
		N += 2;
	cout << N;
}
