#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

typedef long long ll;

string s;
int h, v;

int main() {
	cin >> s;
	if (s[0] - 'a' > 0)
		h++;
	if (s[0] - 'a' < 7)
		h++;
	if (s[1] - '1' > 0)
		v++;
	if (s[1] - '1' < 7)
		v++;
	printf("%d", h + v + h * v);
}
