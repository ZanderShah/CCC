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

int N, v, sum, best, bestDay;
string s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> v;
		sum += v * (s[0] == 'b' ? 1 : -1);
		if (sum > best) {
			bestDay = i + 1;
			best = sum;
		}
	}
	printf("%d", bestDay);
}
