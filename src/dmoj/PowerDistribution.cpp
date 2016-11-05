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

int T, N, M, h[100005], p[100005], e, d, l;

int main() {
	scan(T);
	for (int t = 0; t < T; t++) {
		scan(N);
		M = 0;
		for (int i = 0; i < N; i++) {
			scan(h[i]);
			scan(e);
			if (e)
				p[M] = i;
			M += e;
		}
		d = h[N - 1] - h[0];
		for (int i = 0; i < M - 1; i++) {
			l = 0;
			for (int j = p[i]; j < p[i + 1]; j++)
				l = max(l, h[j + 1] - h[j]);
			d -= l;
		}
		printf("%d\n", d);
	}
}
