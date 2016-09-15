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

ll l1, r1, l2, r2, k;

int main() {
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	printf("%lld", max(r1 - l1 + 1 - (l1 <= k && k <= r1 ? 1 : 0), 0ll));
}
