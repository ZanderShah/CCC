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

const int MAXN = 1005;

int M, N, t;
float D;
struct Planet {
	float x, y, z, v, r;
	bool vis;
} p[MAXN];
struct Waypoint {
	float x, y, z;
} w[MAXN];

inline float distance(float x, float y, float z, Planet p) {
	return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
}

double minimize(int i, int j, Planet p) {
	// translate planet
	float xx = p.x - w[i].x;
	float yy = p.y - w[i].y;
	float zz = p.z - w[i].z;
	// direction vector -> w[j] - w[i]
	float dx = w[j].x - w[i].x;
	float dy = w[j].y - w[i].y;
	float dz = w[j].z - w[i].z;
	// d * (p - w[i]) / (|d|^2)
	float f = (dx * xx + dy * yy + dz * zz) / (dx * dx + dy * dy + dz * dz);
	// f * d + w[i]
	float ax = f * dx + w[i].x;
	float ay = f * dy + w[i].y;
	float az = f * dz + w[i].z;

	float ret = min(distance(w[i].x, w[i].y, w[i].z, p),
			distance(w[j].x, w[j].y, w[j].z, p));
	if (min(w[i].x, w[j].x) <= ax && ax <= max(w[i].x, w[j].x)
			&& min(w[i].y, w[j].y) <= ay && ay <= max(w[i].y, w[j].y)
			&& min(w[i].z, w[j].z) <= az && az <= max(w[i].z, w[j].z))
		ret = min(ret, distance(ax, ay, az, p));
	return ret;
}

int main() {
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%f %f %f %f %f", &p[i].x, &p[i].y, &p[i].z, &p[i].v, &p[i].r);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%f %f %f", &w[i].x, &w[i].y, &w[i].z);
	scanf("%f", &D);
	for (int i = 0; i < M; i++)
		p[i].r += D;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (!p[j].vis && minimize(i - 1, i, p[j]) <= p[j].r * p[j].r) {
				p[j].vis = 1;
				t += p[j].v;
			}
		}
	}
	printf("%d\n", t);
}
