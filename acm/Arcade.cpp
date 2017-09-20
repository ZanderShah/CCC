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

int N, M;
double A[550][550], b[550], tl, tr, bl, br, in;

double *eliminate(double A[550][550], double b[550]) {
	for (int i = 0; i < M; i++) {

		// Pivot largest element to top
		int m = i;
		for (int j = i + 1; j < M; j++)
			if (fabs(A[j][i]) > fabs(A[m][i]))
				m = j;
		swap(A[i], A[m]);
		swap(b[i], b[m]);

		// Eliminate elements in column
		for (int j = i + 1; j < M; j++) {
			double d = A[j][i] / A[i][i];
			b[j] -= d * b[i];
			for (int k = i; k < M; k++)
				A[j][k] -= d * A[i][k];
		}

	}

	for (int i = M - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--) {
			double d = A[j][i] / A[i][i];
			b[j] -= b[i] * d;
			for (int k = i; k < M; k++)
				A[j][k] -= d * A[i][k];
		}

	for (int i = 0; i < M; i++)
		b[i] /= A[i][i];

	return b;
}

int main() {
	scanf("%d", &N);
	M = N * (N + 1) / 2;
	for (int i = 0; i < M; i++)
		scanf("%lf", &b[i]);

	for (int i = 0, j = 0; j < N; j++)
		for (int k = 0; k <= j; k++, i++) {
			scanf("%lf %lf %lf %lf %lf", &tl, &tr, &bl, &br, &in);
			if (i - j - 1 >= 0)
				A[i][i - j - 1] = tl;
			if (i - j >= 0)
				A[i][i - j] = tr;
			if (i + j + 1 < M)
				A[i][i + j + 1] = bl;
			if (i + j + 2 < M)
				A[i][i + j + 2] = br;
			A[i][i] = -1;
			b[i] *= -in;
		}

	double *g = eliminate(A, b);

	printf("%f", g[0]);
}
