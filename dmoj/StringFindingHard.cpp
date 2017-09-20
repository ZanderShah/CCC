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

int T[1000005];
string a, b;

void Faliure() {
	T[0] = -1;
	for (int i = 0, j = -1; i < b.length(); i++, j++, T[i] = j) {
		while (j >= 0 && b[i] != b[j]) {
			j = T[j];
		}
	}
}

int KMP() {
	for (int i = 0, j = 0; i < a.length(); i++, j++) {
		while (j >= 0 && a[i] != b[j]) {
			j = T[j];
		}
		if (j == b.length() - 1) {
			return i - j;
		}
	}
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> a >> b;

	Faliure();
	cout << KMP();
}
