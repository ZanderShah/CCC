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
#include <map>
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
typedef unordered_map<int, int> umii;

ll sum[200005];
pii ind[200005];

int find_subset(int l, int u, int w[], int n, int result[]) {
	for (int i = 0; i < n; i++)
		ind[i] = mp(w[i], i);
	sort(ind, ind + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + ind[i - 1].x;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && sum[j] - sum[i - 1] < l)
			j++;
		if (sum[j] - sum[i - 1] >= l && sum[j] - sum[i - 1] <= u) {
			for (int k = i; k <= j; k++)
				result[k - i] = ind[k - 1].y;
			return j - i + 1;
		}
	}
	return 0;
}

//int result[200];
//int q[] = { 6, 8, 8, 7 };
//
//int main() {
//	int x = find_subset(15, 17, q, 4, result);
//	printf("%d\n", x);
//	for (int i = 0; i < x; i++)
//		printf("%d\n", result[i]);
//}
