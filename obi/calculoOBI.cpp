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

int n, m, a1[10009], a2[10009], maxn;

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a1[i];

    for (int i = 1; i <= m;i++)
    {
        cin >> a2[i];
        if (a2[i])
        {
            int n = i;
            while (a1[n])
            {
                a1[n] = 0;
                n--;
            }
            a1[n] = 1;
        }
    }

    for (int i = 1; i <= max(n, m); i++)
        if (a1[i]) maxn = i;

    if (!maxn) cout << 0;
    else
        for (int i = 1; i <= maxn; i++)
            cout << a1[i] << ' ';

    cout << endl;
}