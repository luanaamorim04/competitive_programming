#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define EPS 1e-9
#define INF 1e12
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct tpoint
{
    double x, y;
    tpoint operator +(tpoint q) const{
        return {x + q.x, y + q.y};
    }
    tpoint operator -(tpoint q) const{
        return {x - q.x, y - q.y};
    }
    ll operator *(tpoint q) const{
        return ((x*q.x) + (y*q.y));
    }
    double operator ^(tpoint q) const{
        return ((x*q.y) - (q.x*y));
    }
    double operator ~() const{
        return hypot(x, y);
    }
};

int n, m, tot, dentro;
tpoint vertex[1<<10], point[1<<10], inf;

int f(ll x)
{
    return (x < 0 ? -1 : (x != 0));
}

int boundary(tpoint a, tpoint b, tpoint c)
{
    double distac = (~(a-c));
    double distbc = (~(b-c));
    double distab = (~(a-b));
    return (fabs(distab - (distac + distbc)) < EPS);
}

ll line_segment_intersection(tpoint a, tpoint b, tpoint c, tpoint d)
{
    ll cross1 = (b-a)^(c-a), cross2 = (b-a)^(d-a), cross3 = (d-c)^(a-c), cross4 = (d-c)^(b-c);
    if (boundary(a, b, c)) return 1;
    if (boundary(a, b, d)) return 1;
    if (boundary(c, d, a)) return 1;
    if (boundary(c, d, b)) return 1;

    return (f(cross1)*f(cross2) < 0 && f(cross3)*f(cross4) < 0);
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> vertex[i].x >> vertex[i].y;
    for (int i = 0; i < m; i++)     
        cin >> point[i].x >> point[i].y;

    inf.x = INF, inf.y = INF;
    for (int i = 0; i < m; i++)
    {
        tot = dentro = 0;
        for (int j = 0; j < n; j++)
        {
            tot += line_segment_intersection(point[i], inf, vertex[j], vertex[(j + 1) % n]),
            dentro |= boundary(vertex[j], vertex[(j + 1) % n], point[i]);
            tot -= (boundary(point[i], inf, vertex[j]));
        }

        cout << (dentro ? "BOUNDARY" : ((tot&1) ? "INSIDE" : "OUTSIDE")) << endl;
    }
}
