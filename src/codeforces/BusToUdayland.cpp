#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <queue>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 3000;

int n;
char c[MAXN][5];
bool valid;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
		if (!valid) {
			if (c[i][0] == c[i][1] && c[i][0] == 'O') {
				c[i][0] = c[i][1] = '+';
				valid = true;
			} else if (c[i][3] == c[i][4] && c[i][3] == 'O') {
				c[i][3] = c[i][4] = '+';
				valid = true;
			}
		}
	}

	if (!valid) {
		printf("NO");
	} else {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++)
				printf("%c", c[i][j]);
			printf("\n");
		}
	}
}
