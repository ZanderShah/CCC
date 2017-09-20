#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int N, K, v[MAXN];
ll first[MAXN], rest[MAXN], ans;

int main() {
	scan(N);
	scan(K);

	for (int i = 1, x; i <= N; i++) {
		scan(x);
		v[x] = i;
	}
	for (int i = 1, c = 1; i <= N; i++) {
		first[i] = first[i - 1] + (v[i] - c + N) % N;
		c = v[i];
	}
	for (int i = 1, c = v[N]; i <= N; i++) {
		rest[i] = rest[i - 1] + (v[i] - c + N) % N;
		c = v[i];
	}

	if (K <= N)
		printf("%lld", first[K]);
	else
		printf("%lld", first[N] + (K - N) / N * rest[N] + rest[(K - N) % N]);
}
