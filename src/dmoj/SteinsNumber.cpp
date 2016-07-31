#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define mp make_pair
using namespace std;

int Q;
long long l, r;
vector<int> ternary;

long long query(long long n)
{
	// Thanks wolfram
	long long x = 450283905890997363ll;

	while (x)
	{
		ternary.push_back(n / x);
		n %= x;
		x /= 3;
	}

	for (int i = 0; i < ternary.size(); i++)
		if (ternary[i] > 1)
			for (; i < ternary.size(); i++)
				ternary[i] = 1;

	long long binary = 0, multiplier = 1;
	for (; !ternary.empty(); multiplier *= 2)
	{
		if (ternary[ternary.size() - 1])
			binary += multiplier;
		ternary.pop_back();
	}
	return binary;
}

int main()
{
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", query(r) - query(l - 1));
	}
}
