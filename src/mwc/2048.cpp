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
#include <stdio.h>

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

int N, s[64], m;

int main() {
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++) {
		scanf("%d", &x);
		for (int j = 0; j < 25; j++) {
			if (x >> j & 1) {
				s[j]++;
			}
		}
	}
	for (int i = 1; i < 63; i++) {
		s[i] += s[i - 1] / 2;
		if (s[i]) {
			m = i;
		}
	}
	printf("%lld", 1ll << m);
}
