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

const double EPS = 1e-5;
int Q, T, N, F;

int main() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &T, &N, &F);
		if (T == 1) {
			printf("%lld\n", (ll) ceil(pow(N, 1.0 / F) - EPS - 1));
		} else {
			printf("%lld\n", (ll) ceil(log(N) / log(F + 1) - EPS));
		}
	}
}
