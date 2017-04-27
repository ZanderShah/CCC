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
#include <cassert>

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

int N;
bool A[305][305], b[305];
char s[15];

void printMatrix() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d", A[i][j]);
		}
		printf("|%d\n", b[i]);
	}
	printf("\n");
}

inline int basic(int i) {
	int j = i;
	while (j <= N && A[i][j] == 0) {
		++j;
	}
	return j;
}

int main() {
	scanf("%d", &N);

	for (int i = 1, p, q; i <= N; ++i) {
		scanf(" %s", s);
		if (s[0] == '!') {
			sscanf(s, "!%d", &p);
			A[i][p] ^= 1;
		} else {
			sscanf(s, "%d==%d", &p, &q);
			A[i][p] ^= 1;
			A[i][q] ^= 1;
		}

		A[i][i] ^= 1;
		b[i] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		// Pivot largest element to top
		int m = i;
		for (int j = 1; j < i; ++j) {
			if (basic(j) == i) {
				m = j;
			}
		}
		for (int j = i + 1; j <= N; j++) {
			if (A[j][i]) {
				m = j;
			}
		}

		if (A[m][i] == 0) continue;

		swap(A[i], A[m]);
		swap(b[i], b[m]);

		// Eliminate elements in column
		for (int j = 1; j <= N; ++j) {
			if (i == j || A[j][i] == 0) continue;

			b[j] ^= b[i];
			for (int k = i; k <= N; ++k) {
				A[j][k] ^= A[i][k];
			}
		}
	}

	// printMatrix();

	// Back substitution
	for (int i = N; i >= 1; --i) {
		if (A[i][i] == 0 && b[i] == 1) {
			printf("No perfect solution found\n");
			return 0;
		}

		if (b[i] == 0) continue;

		// Update matrix
		for (int k = i - 1; k >= 1; --k) {
			b[k] ^= A[k][i];
			A[k][i] = 0;
		}

		// printMatrix();
	}

	for (int i = 1; i <= N; ++i) {
		printf("%s\n", b[i] ? "true" : "false");
	}
}
