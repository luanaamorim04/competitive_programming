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
        return {(x*q.x) + (y*q.y)};
    }
    ll operator ^(tpoint q) const{
        return (x*q.y) - (q.x*y);
    }
    double operator ~() const{
        return hypot(x, y);
    }
};

tpoint a, b, c;
int n;

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        tpoint u = b-a, v = c-a;
        ll resp = u^v;
        cout << (!resp ? "TOUCH" : (resp < 0 ? "RIGHT" : "LEFT")) << endl;
    } 
}
