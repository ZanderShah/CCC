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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
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

int y;

void Julian() {
	if (y % 4 == 0) {
		printf("12.09.%d\n", y);
	} else {
		printf("13.09.%d\n", y);
	}
}

void Weird() {
	printf("26.09.%d\n", y);
}

void Gregorian() {
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		printf("12.09.%d\n", y);
	} else {
		printf("13.09.%d\n", y);
	}
}

int main () {
	scanf("%d", &y);
	if (y <= 1917) {
		Julian();
	} else if (y == 1918) {
		Weird();
	} else {
		Gregorian();
	}
}
