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

const ll MOD = 1e9 + 7;

int N;
ll A[550][550], det = 1;

ll p(ll x, ll n) {
	ll ret = 1;
	for (int i = 0; i < 63; i++, x = x * x % MOD)
		if (n >> i & 1)
			ret = ret * x % MOD;
	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%lld", &A[i][j]);
			if (A[i][j] < 0)
				A[i][j] += MOD;
		}

	for (int i = 0; i < N; i++) {
		// Pivot largest element to top
		int m = i;
		for (int j = i + 1; j < N; j++)
			if (A[j][i] > A[m][i])
				m = j;

		if (i != m) {
			det *= -1;
			swap(A[i], A[m]);
		}

		// Eliminate elements in column
		for (int j = i + 1; j < N; j++) {
			ll d = A[j][i] * p(A[i][i], MOD - 2) % MOD;
			for (int k = i; k < N; k++)
				A[j][k] = (A[j][k] - d * A[i][k] % MOD + MOD) % MOD;
		}
	}

	if (det < 0)
		det += MOD;

	for (int i = 0; i < N; i++)
		det = det * A[i][i] % MOD;

	printf("%lld", det);
}
