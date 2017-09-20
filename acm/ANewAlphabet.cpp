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

int n;

string c[26] = { "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<",
		"1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|",
		"\\/", "\\/\\/", "}{", "`/", "2" };
string s;

int main() {
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << c[s[i] - 'A'];
		else if (s[i] >= 'a' && s[i] <= 'z')
			cout << c[s[i] - 'a'];
		else
			cout << s[i];
	}
}
