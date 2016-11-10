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
typedef pair<ll, ll> pll;

int T, M, N, X, Y, x, y;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		x = y = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &x, &y);
			X = max(x, X);
			Y = max(y, Y);
		}
		if (X + Y > N)
			printf("-1\n");
		else {
			for (int i = 0; i < X; i++)
				printf("a");
			for (int i = X; i < N; i++)
				printf("b");
			printf("\n");
		}
	}
}
