#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int t, s[1 << 19];
ll x;
char c;

int pattern(ll x) {
	int ret = 0;
	for (int i = 0; x; i++) {
		if (x % 2)
			ret += 1ll << i;
		x /= 10;
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf(" %c %lld", &c, &x);
		if (c == '?')
			printf("%d\n", s[pattern(x)]);
		else
			s[pattern(x)] += c == '+' ? 1 : -1;
	}
}
