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

int t, n, p[101], d[101];

int f(int ini, int fim, int depth)
{
    if (ini > fim) return 0;
    int maior = 0, idx;
    for (int i = ini; i <= fim; i++)
    {
        if (maior < p[i]) 
        {
            maior = p[i];
            idx = i;
        }
    }

    d[maior] = depth;

    f(idx + 1, fim, depth + 1);
    f(ini, idx - 1, depth + 1);
    return 0;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        f(0, n - 1, 0);

        for (int i = 0; i < n; i++)
            cout << d[p[i]] << ' ';

        cout << endl;
    }
}   