#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 20;

int n, t[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		printf("%d ", t[i]);
	}
	printf("\n");
	while (true) {
		bool change = false;
		for (int i = 0; i < n - 1; i++)
			if (t[i] > t[i + 1]) {
				int temp = t[i];
				t[i] = t[i + 1];
				t[i + 1] = temp;

				for (int i = 0; i < n; i++)
					printf("%d ", t[i]);
				printf("\n");

				change = true;
			}

		if (!change)
			break;
	}
}
