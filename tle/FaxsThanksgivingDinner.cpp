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

int N, C;
set<int> d;

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0, c; i < C; i++) {
		scanf("%d", &c);
		for (int j = 1; j <= c / j; j++)
			if (c % j == 0) {
				d.insert(j);
				d.insert(c / j);
			}
	}
	bool happy = 1;
	for (int i = 0, n; i < N; i++) {
		scanf("%d", &n);
		for (int j = 2; j <= n / j; j++)
			if (n % j == 0) {
				if (d.find(j) == d.end())
					happy = 0;
				else
					while (n != 1 && n % j == 0)
						n /= j;
			}
		if (n != 1 && d.find(n) == d.end())
			happy = 0;
	}
	printf("%c", happy ? 'Y' : 'N');
}
