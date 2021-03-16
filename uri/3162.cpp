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
#define INF 1<<20
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x[1<<10], y[1<<10], z[1<<10], n;

ll dist(int i, int j)
{
    return ((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j])) + ((z[i]-z[j])*(z[i]-z[j]));
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll dist_ = INF;
        for (int j = 0; j < n; j++)
        {
            if (i != j) dist_ = min(dist_, dist(i, j));
        }
        if (dist_ <= 400) cout << "A\n";
        else if (dist_ <= 2500) cout << "M\n"; 
        else cout << "B\n";
    }
}