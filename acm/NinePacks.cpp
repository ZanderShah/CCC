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

int H, h[101], dpH[101][100001], B, b[101], dpB[101][100001];

int main() {
	scanf("%d", &H);
	for (int i = 1; i <= H; i++)
		scanf("%d", &h[i]);
	dpH[0][0] = 1;
	for (int i = 1; i <= H; i++)
		for (int j = 0; j < 100001; j++) {
			dpH[i][j] = dpH[i - 1][j];
			if (j - h[i] >= 0 && dpH[i - 1][j - h[i]])
				dpH[i][j] =
						dpH[i][j] ?
								min(dpH[i][j], dpH[i - 1][j - h[i]] + 1) :
								dpH[i - 1][j - h[i]] + 1;
		}
	scanf("%d", &B);
	for (int i = 1; i <= B; i++)
		scanf("%d", &b[i]);
	dpB[0][0] = 1;
	for (int i = 1; i <= B; i++)
		for (int j = 0; j < 100001; j++) {
			dpB[i][j] = dpB[i - 1][j];
			if (j - b[i] >= 0 && dpB[i - 1][j - b[i]])
				dpB[i][j] =
						dpB[i][j] ?
								min(dpB[i][j], dpB[i - 1][j - b[i]] + 1) :
								dpB[i - 1][j - b[i]] + 1;
		}
	int ans = 1e9;
	for (int i = 1; i < 100001; i++)
		if (dpH[H][i] && dpB[B][i])
			ans = min(ans, dpH[H][i] + dpB[B][i] - 2);

	if (ans == 1e9)
		printf("impossible");
	else
		printf("%d", ans);
}
