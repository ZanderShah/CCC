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
#include <map>
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
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

int N, group[100], g;
char s[10];

int main() {
	scanf("%d", &N);
	g = 0;
	for (int i = 0; i < N; i++)
		group[i] = 1;
	for (int i = 0; i < N; i++) {
		scanf(" %s", s);
		switch (s[0]) {
		case 'o':
			g++;
			break;
		case 'f':
			group[g] = 0;
			break;
		case 'u':
			if (group[g])
				group[g] = 2;
			break;
		}
	}

	for (int i = 0; i <= g; i++) {
		if (group[i] & 1) {
			printf("true");
			return 0;
		}
	}
	for (int i = 0; i <= g; i++) {
		if (group[i] & 2) {
			printf("unknown");
			return 0;
		}
	}
	printf("false");
}
