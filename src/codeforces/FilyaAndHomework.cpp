#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n, a[100001];
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int u = 1;
	v.pb(a[0]);
	for (int i = 1; i < n; i++)
		if (a[i - 1] != a[i]) {
			u++;
			v.pb(a[i]);
		}
	if (u <= 2)
		printf("YES");
	else if (u == 3 && v[2] + v[0] == 2 * v[1])
		printf("YES");
	else
		printf("NO");
}
