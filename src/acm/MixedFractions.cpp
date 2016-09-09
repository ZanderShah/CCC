#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1;

int x, y;

int main() {
	do {
		scanf("%d %d", &x, &y);
		if (x || y) {
			printf("%d %d / %d\n", x / y, x % y, y);
		}
	} while (x || y);
}
