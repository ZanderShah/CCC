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

const double PI = 3.14159265359, E = exp(1.0);

int n;
string s;
string l[9] = { "1", "2", "6", "24", "120", "720", "5040", "40320", "362880" };

double Sterling(int n) {
	return floor(log10(2 * PI * n) / 2 + n * log10(n / E));
}

int main() {
	cin >> s;
	int goal = s.length();

	if (s.length() < 7) {
		for (int i = 0; i < 9; i++)
			if (s == l[i]) {
				printf("%d", i + 1);
				return 0;
			}
	} else {
		// Every other factorial will increase magnitude by at least 1
		// Stirling approximation n! ~ sqrt(2 * PI * n) * (n / e) ^ n
		// If this works ...

		int ans = 1;
		while (1) {
			if (Sterling(ans) >= goal) {
				printf("%d", ans - 1);
				return 0;
			}
			ans++;
		}
	}
}
