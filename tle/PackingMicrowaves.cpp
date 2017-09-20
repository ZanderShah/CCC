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

int N, X, Y, Z, B[3];
ll t = 1ll << 60;

ll compute(ll a, ll b, ll c) {
	ll mx = X / a, my = Y / b, mz = Z / c;
	if (!mx || !my || !mz)
		return 1ll << 60;
	return ceil(N * 1.0 / mx / my / mz);
}

int main() {
	scanf("%d", &N);
	scanf("%d %d %d", &B[0], &B[1], &B[2]);
	scanf("%d %d %d", &X, &Y, &Z);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (i != j && i != k && j != k)
					t = min(t, compute(B[i], B[j], B[k]));
	if (t == 1ll << 60)
		printf("SCAMMED");
	else
		printf("%lld", t);
}
