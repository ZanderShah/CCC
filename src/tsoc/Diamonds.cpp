#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1e5;

int n;

int main() {
	scanf("%d", &n);

	for (int i = 0, l = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", abs(n / 2 - j) < l ? ' ' : '*');
		l += i < n / 2 ? 1 : -1;
		printf("\n");
	}
}
