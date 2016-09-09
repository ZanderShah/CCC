#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 102;

int W, P, s[MAXN];
set<int> a;

int main() {
    scanf("%d %d", &W, &P);
    for (int i = 1; i <= P; i++)
    	scanf("%d", &s[i]);
    s[P + 1] = W;
    for (int i = 0; i <= P + 1; i++)
    	for (int j = i + 1; j <= P + 1; j++)
    		a.insert(s[j] - s[i]);

    for (set<int>::iterator i = a.begin(); i != a.end(); i++)
    	printf("%d ", *i);
}
