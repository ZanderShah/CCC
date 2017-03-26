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

int N, Q, J, l, r;
bool A[1000005], NOR[1005][2];

bool query(int l, int r) {
	bool ret = A[l - 1];
	while (l <= r) {
		if (l % J == 0 && l + J <= r) {
			ret = NOR[l / J][ret];
			l += J;
		} else {
			ret = !ret & !A[l];
			l++;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	J = floor(sqrt(N));
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i <= J; i++) {
		// Previous NOR chain was 0 or 1
		NOR[i][0] = 0;
		NOR[i][1] = 1;
		for (int j = i * J; j < min((i + 1) * J, N); j++) {
			NOR[i][0] = !NOR[i][0] && !A[j];
			NOR[i][1] = !NOR[i][1] && !A[j];
		}
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", query(l, r - 1));
	}
}
