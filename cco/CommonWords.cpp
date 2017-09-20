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
typedef pair<ll, ll> pll;
typedef unordered_map<int, int> umii;

int n, m, k;
vector<pair<int, string> > order;
map<string, int> words;
string w;

inline string ordinal(int i) {
	i %= 100;
	if (i == 11 || i == 12 || i == 13)
		return "th";
	else if (i % 10 == 1)
		return "st";
	else if (i % 10 == 2)
		return "nd";
	else if (i % 10 == 3)
		return "rd";
	return "th";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int t = 0; t < n; t++) {
		order.clear();
		words.clear();
		cin >> m >> k;
		cout << k << ordinal(k) << " most common word(s):" << endl;
		for (int i = 0; i < m; i++) {
			cin >> w;
			words[w]++;
		}
		for (auto i = words.begin(); i != words.end(); i++)
			order.pb(mp(i->second, i->first));
		sort(order.begin(), order.end());
		for (int i = order.size() - 1, d = 1; i >= 0 && k > 0; i--) {
			if (k == 1)
				cout << order[i].y << endl;
			if (order[i].x != order[i - 1].x) {
				k -= d;
				d = 1;
			} else {
				d++;
			}
		}
		cout << endl;
	}
}
