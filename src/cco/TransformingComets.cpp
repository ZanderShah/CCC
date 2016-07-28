#include <bits/stdc++.h>
#define pii pair<int, int>
#define pff pair<float, float>
#define mp make_pair
#define f first
#define s second
using namespace std;

int R, N, A, B, T[500005];
pff a[1000005], b[500005];
pii c[500005];

void Faliure()
{
	T[0] = -1;
	for (int i = 0, j = -1; i < B; i++, j++, T[i] = j)
		while (j >= 0 && b[i] != b[j])
			j = T[j];
}

int KMP()
{
	for (int i = 0, j = 0; i < A; i++, j++)
	{
		while (j >= 0 && a[i] != b[j])
			j = T[j];
		if (j == B - 1)
			return i - j + 1;
	}
	return 0;
}

float rat(pii x, pii y, pii z)
{
	pii i = mp(x.f - y.f, x.s - y.s), j = mp(z.f - y.f, z.s - y.s);
	float ret = sqrt(i.f * i.f + i.s * i.s) / sqrt(j.f * j.f + j.s * j.s);
    return ret;
}

float angle(pii x, pii y, pii z)
{
	pii i = mp(x.f - y.f, x.s - y.s), j = mp(z.f - y.f, z.s - y.s);
	// A x B / A * B -> tan(x)
	float ret = atan2(i.f * j.s - i.s * j.f, i.f * j.f + i.s * j.s);
	return ret;
}

void prepare(pff* v, int L)
{
	for (int i = 0; i < N; i++)
		scanf("%d %d", &c[i].f, &c[i].s);
	for (int i = 0; i <= L; i++)
	{
		v[i].f = angle(c[i % N], c[(i + 1) % N], c[(i + 2) % N]);
		v[i].s = rat(c[i % N], c[(i + 1) % N], c[(i + 2) % N]);
	}
}

int main()
{
	scanf("%d", &R);

	for (int i = 0; i < R; i++)
	{
		scanf("%d", &N);

		prepare(b, B = N);
		prepare(a, A = 2 * N);
		Faliure();
		printf("%d\n", KMP());
	}
}
