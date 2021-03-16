#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, x, p, ok;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x <= p)
            p = x + m;
        else 
            ok = 1;
    }

    if (p < 42195) ok = 1;

    cout << (ok ? 'N' : 'S');
}