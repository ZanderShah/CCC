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

int C, R, w;
string s;
set<char> clrs;

int main() {
	scanf("%d %d", &C, &R);
	getline(cin, s);
	for (int i = 0; i < R; i++) {
		getline(cin, s);
		for (int j = 0; j < C; j++) {
			if (s[j] != ' ') {
				w++;
				clrs.insert(s[j]);
			}
		}
	}
	printf("%d", w + clrs.size() - (clrs.find('.') != clrs.end()));
}
