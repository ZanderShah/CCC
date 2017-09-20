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
#include <stdio.h>

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

int G, P;
set<int> s;

int main() {
	scanf("%d %d", &G, &P);
	s.insert(0);
	for (int i = 1; i <= G; i++)
		s.insert(i);
	s.insert(G + 1);
	for (int i = 1, x; i <= P; i++) {
		scanf("%d", &x);
		auto it = s.lower_bound(x);
		while (*it > min(x, G)) {
			it--;
		}
		if (*it == 0) {
			printf("%d\n", i - 1);
			return 0;
		}
		s.erase(*it);
	}
	printf("%d\n", P);
}
