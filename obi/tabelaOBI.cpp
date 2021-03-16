#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int j, v, p , e, d;

int main()
{_  
    cin >> j >> p >> v >> e >> d;
    if (j == -1)
    {
        if (v == -1) v = (p - e) / 3;
        else if (e == -1) e = (p - 3*v);
        else if (p == -1) p = 3*v + e;

        j = v + e + d;
    }
    else if (v == -1)
    {
        if (d == -1)
        {
            v = (p - e) / 3;
            d = j - v - e;
        } 
        else if (p == -1)
        {
            v = j - e - d;
            p = 3*v + e;
        }
        else if (e == -1)
        {
            v = (d + p - j) / 2;
            e = j - v - d;
        }

        v = (p - e) / 3;
    }
    else if (e == -1)
    {
        if (d == -1)
        {
            e = p - 3*v;
            d = j - e - v;
        }
        else if (p == -1)
        {
            e = j - v - d;
            p = 3*v + e;
        }

        e = j - v - d;
    }
    else if (d == -1)
    {
        d = j - e - v;
        p = 3*v + e;
    }
    else if (p == -1)
    {
        p = 3*v + e;
    }
    cout << j << ' ' << p << ' ' << v << ' ' << e << ' ' << d << endl;
}