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

int N, M, tyme[305][305], totalEdges[305];
double A[305][305], b[305], total;

double *eliminate(double A[305][305], double b[305]) {
	for (int i = 1; i <= N; i++) {

		// Pivot largest element to top
		int m = i;
		for (int j = i + 1; j <= N; j++)
			if (fabs(A[j][i]) > fabs(A[m][i]))
				m = j;
		swap(A[i], A[m]);
		swap(b[i], b[m]);

		// Eliminate elements in column
		for (int j = i + 1; j <= N; j++) {
			double d = A[j][i] / A[i][i];
			b[j] -= d * b[i];
			for (int k = i; k <= N; k++)
				A[j][k] -= d * A[i][k];
		}

	}

	for (int i = N; i > 0; i--)
		for (int j = i - 1; j > 0; j--) {
			double d = A[j][i] / A[i][i];
			b[j] -= b[i] * d;
			for (int k = i; k <= N; k++)
				A[j][k] -= d * A[i][k];
		}

	for (int i = 1; i <= N; i++)
		b[i] /= A[i][i];

	return b;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0, u, v, w; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		tyme[u][v] += w;
		tyme[v][u] += w;
		totalEdges[u]++;
		totalEdges[v]++;
	}
	total = 0;

	// percentage -> 1 / totalEdges[x]
	// end -> assuming girl is at this spot
	// start -> starting spot to find girl
	// f(start, end) = p(start, end) * t(start, end) + ∑ p(start, middle) * (f(middle, end) + time(middle, end))

	// solve for expected time by averaging times across all end points
	// solve for specific end point by organizing into augmented matrix [A|b]
	// A[start] = f(start, end) - ∑ p(start, middle) * f(middle, end)
	// A[start] = [-p(start, 1) -p(start, 2) .. 1 .. -p(start, n)], A[end] = 0
	// b[start] = p(start,end) * t(start, end) + ∑ p(start, middle) * time(middle, end), b[end] = 0

	for (int end = 2; end <= N; end++) {
		for (int start = 1; start <= N; start++) {
			for (int middle = 1; middle <= N; middle++) {
				if (totalEdges[start])
					b[start] -= tyme[middle][end] / totalEdges[start];
				else
					b[start] = 0;
				A[start][middle] = -1 / totalEdges[start];
			}
			A[start][start] = 1;
			if (totalEdges[start])
				b[start] += 2 * tyme[start][end] / totalEdges[start];
		}

		for (int i = 1; i <= N; i++)
			A[end][i] = 0;
		b[end] = 0;

		double *r = eliminate(A, b);
		total += r[1];
	}

	printf("%f", total / N);
}
