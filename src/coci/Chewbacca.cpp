#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <type_traits>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std; 
typedef long long ll;

ll N, x, y;
int K, Q, d;

int main() {
	scanf("%lld %d %d", &N, &K, &Q);

	for (int i = 0; i < Q; i++) {
		scanf("%lld %lld", &x, &y);
		if (K == 1)
			printf("%lld\n", abs(x - y));
		else {
			d = 0;

			while (x != y) {
				if (x < y)
					swap(x, y);
				x = (x + K - 2) / K;
				d++;
			}

			printf("%d\n", d);
		}
	}
}
