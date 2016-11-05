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

int T, n, X[100005], Y[100005];

int main() {
	scan(T);
	for (int t = 0; t < T; t++) {
		scan(n);
		for (int i = 0; i < n; i++)
			scan(X[i]);
		for (int i = 0; i < n; i++)
			scan(Y[i]);

		int d = 0;
		for (int i = 0, j = 0; i < n; i++) {
			while (j + 1 < n && Y[j + 1] >= X[i])
				j++;
			d = max(d, j - i);
		}

		printf("The maximum distance is %d\n", d);
	}
}
