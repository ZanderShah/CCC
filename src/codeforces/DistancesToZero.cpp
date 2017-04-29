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
#include <string>
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

int n, a[200005];
vector<int> zero;

int main() {
	scanf("%d", &n);

	zero.pb(-200005);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			zero.pb(i);
		}
	}
	zero.pb(400005);

	for (int i = 1, j = 0; i <= n; i++) {
		while (zero[j + 1] < i) {
			j++;
		}
		printf("%d ", min(i - zero[j], zero[j + 1] - i));
	}
}
