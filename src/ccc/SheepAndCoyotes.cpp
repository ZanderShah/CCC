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

int n;
pff sheep[105];
bool eat[105];

inline double dist(double i, int j) {
	return (sheep[j].x - i) * (sheep[j].x - i) + sheep[j].y * sheep[j].y;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%f %f", &sheep[i].x, &sheep[i].y);
	for (double i = 0; i <= 1000; i += 0.01) {
		int e = 0;
		for (int j = 1; j < n; j++)
			if (dist(i, j) < dist(i, e))
				e = j;
		eat[e] = 1;
	}
	for (int i = 0; i < n; i++)
		if (eat[i])
			printf("The sheep at (%.2f, %.2f) might be eaten.\n", sheep[i].x,
					sheep[i].y);
}
