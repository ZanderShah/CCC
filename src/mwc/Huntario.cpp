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

string A, B, B1, B2;
int AA, BB, T[1000005];
vector<int> ans;

void Faliure() {
	T[0] = -1;
	for (int i = 0, j = -1; i < BB; i++, j++, T[i] = j) {
		while (j >= 0 && B1[i] != B1[j]) {
			j = T[j];
		}
	}
}

int KMP() {
	int j = 0;
	for (int i = 0; i < AA; i++, j++) {
		while (j >= 0 && A[i] != B1[j]) {
			j = T[j];
		}
	}
	j--;
	if (j == -1) {
		return AA;
	}
	return AA - j - 1;
}

int main() {
	cin >> A >> B1;
	if (A.length() < B1.length()) {
		B2 = B1.substr(A.length());
		B1 = B1.substr(0, A.length());
	}
	AA = A.length();
	BB = B1.length();
	Faliure();
	int x = KMP();
	cout << A.substr(0, x) << B1 << B2 << endl;
}
