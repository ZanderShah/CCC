#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1e5;
string s;

int main() {
	cin >> s;
	int i = 0;
	while (i < s.length() && s[i] == 'a')
		i++;
	int j = i;
	while (j < s.length() && s[j] != 'a')
		j++;

	if (i == s.length())
		i = s.length() - 1;

	for (int k = 0; k < s.length(); k++)
		if (i <= k && k < j)
			cout << (char) ((s[k] - 'a' + 25) % 26 + 'a');
		else
			cout << s[k];
}
