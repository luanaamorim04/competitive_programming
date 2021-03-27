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
#define INF 99999999
#define EPS 1e-9
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
struct tpoint
{
    ll x, y;
    tpoint operator +(tpoint q) const{
        return {x + q.x, y + q.y};
    }
    tpoint operator -(tpoint q) const{
        return {x - q.x, y - q.y};
    }
    ll operator *(tpoint q) const{
        return ((x*q.x) + (y*q.y));
    }
    ll operator ^(tpoint q) const{
        return ((x*q.y) - (q.x*y));
    }
    double operator ~() const{
        return hypot(x, y);
    }
    int operator ==(tpoint q) const{
        return ((q.x == x) && (q.y == y));
    }
};
 
tpoint a, b, c, d;
ll n, cross1, cross2, cross3, cross4;
 
int sign(ll x)
{
    return ((x < 0) ? -1 : (x > 0));
}

int interval(tpoint a, tpoint b, tpoint c)
{
    if (max(b.x, a.x) >= c.x && min(a.x, b.x) <= c.x)
        if (max(b.y, a.y) >= c.y && min(a.y, b.y) <= c.y)
            return 1;
    return 0;
}

int dentro(tpoint a, tpoint b, tpoint c)
{
    double distac = (~(a-c));
    double distbc = (~(b-c));
    double distab = (~(a-b));
    return (fabs(distab - (distac + distbc)) < EPS);
}
 
int segment_intersection(tpoint a, tpoint b, tpoint c, tpoint d)
{
    cross1 = (b-a)^(c-a), cross2 = (b-a)^(d-a), cross3 = (d-c)^(a-c), cross4 = (d-c)^(b-c);
    // if (!cross1 && interval(a, b, c)) return 1;
    // if (!cross2 && interval(a, b, d)) return 1;
    // if (!cross3 && interval(c, d, a)) return 1;
    // if (!cross4 && interval(c, d, b)) return 1;
    if (dentro(a, b, c)) return 1;
    if (dentro(a, b, d)) return 1;
    if (dentro(c, d, a)) return 1;
    if (dentro(c, d, b)) return 1;
 
    return (sign(cross1)*sign(cross2) < 0) && (sign(cross3)*sign(cross4) < 0);
}
 
int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        cout << (segment_intersection(a, b, c, d) ? "YES" : "NO") << endl;
    } 
}