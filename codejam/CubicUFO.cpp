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
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

int T;
double A;
double rot_z[3][3], rot_x[3][3];

void setz(double theta)
{
    double t[3][3] = {{
        cos(theta), -sin(theta), 0
    }, {
        sin(theta), cos(theta), 0
    }, {
        0, 0, 1
    }};
    swap(rot_z, t);
}

void setx(double theta)
{
    double t[3][3] = {{
        1, 0, 0
    }, {
        0, cos(theta), -sin(theta)
    }, {
        0, sin(theta), cos(theta)
    }};
    swap(rot_x, t);
}

void mult(double (&a)[3][3], double (&b)[3][3])
{
    double t[3][3];
    memset(t, 0, sizeof t);

    for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 3; ++k)
        t[i][j] = t[i][j] + a[i][k] * b[k][j];

    swap(t, b);
}

int ccw(pdd a, pdd b, pdd c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool pt_sort(pdd u, pdd v)
{
    if (fabs(u.x - v.x) < 1e-9)
        return u.y < v.y;
    return u.x < v.x;
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%lf", &A);
        printf("Case #%d:\n", t);

        if (A <= sqrt(2))
        {
            // Finding x value of rotated (0.5, 0.5, 0.5)
            // Solving A / 2 = 0.5 * cos(theta) + 0.5 * sin(theta)
            setz(asin(A / sqrt(2)) - M_PI / 4);
            setx(0);
        }
        else
        {
            // Full rotate z
            setz(M_PI / 4);
            setx(asin(A / sqrt(3)) - atan(sqrt(2)));
        }

        double pos[3][3] = {{
            0.5, 0, 0
        }, {
            0, 0.5, 0
        }, {
            0, 0, 0.5
        }};

        mult(rot_z, pos);
        mult(rot_x, pos);

#if 1
        for (int i = 0; i < 3; ++i)
            printf("%.9lf %.9lf %.9lf\n", pos[0][i], pos[1][i], pos[2][i]);
#else
        vector<pdd> pts;
        for (int i = 0; i < 8; ++i)
        {
            pdd pt(0, 0);
            for (int j = 0; j < 3; ++j)
            {
                if (i >> j & 1)
                {
                    pt.x += pos[0][j];
                    pt.y += pos[2][j];
                }
                else
                {
                    pt.x -= pos[0][j];
                    pt.y -= pos[2][j];
                }
            }
            pts.pb(pt);
            cout << pt.x << " " << pt.y << endl;
        }
#endif
    }
}
