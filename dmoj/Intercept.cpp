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

int Q, N;
ll x[15], xx0, yy0, a[15], xx, aa;

void genr(int i, int s, ll p) {
	if (i == N) {
		a[s] += p;
		return;
	}
	genr(i + 1, s + 1, -p * x[i]);
	genr(i + 1, s, p);
}

int main () {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &x[i]);
		}
		memset(a, 0, sizeof a);
		scanf("%lld %lld", &xx0, &yy0);
		genr(0, 0, 1);
		xx = 1;
		for (int i = 0; i < N; i++) {
			xx *= (xx0 - x[i]);
		}
		aa = yy0 / xx;
		for (int i = 0; i <= N; i++) {
			cout << a[i] * aa << " ";
		}
		cout << endl;
	}
}
