#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

const int MAXN = 1e7 + 1;

ll cw[MAXN], ccw[MAXN];

ll delivery(int N, int K, int L, int p[]) {
	for (int i = 0; i < N; i++)
		if (i < K) {
			cw[i] = min(2 * p[i], L);
			ccw[N - 1 - i] = min(2 * (L - p[N - 1 - i]), L);
		} else {
			cw[i] = cw[i - K] + min(2 * p[i], L);
			ccw[N - 1 - i] = ccw[N - 1 - i + K] + min(2 * (L - p[N - 1 - i]), L);
		}

	ll ret = min(cw[N - 1], ccw[0]);
	for (int i = 0; i < N - 1; i++)
		ret = ret == -1 ? cw[i] + ccw[i + 1] : min(cw[i] + ccw[i + 1], ret);
	return ret;
}
