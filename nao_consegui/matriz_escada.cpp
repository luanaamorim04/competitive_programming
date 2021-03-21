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

int n, m, tab[1009][1009], passou[1009], ok, k;

int main()
{_
    cin >> n >> m;
    ok = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = 0; k = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> tab[i][j];
            k += tab[i][j];
            if (passou[0] && tab[i][j]) ok = 0;
            if (passou[j] && tab[i][j]) ok = 0;
            if (tab[i][j] && !x)
            {
                passou[j] = 1;
                x = 1;
            }
        }

        if (!k) passou[0] = 1;
    }

    cout << (ok ? 'S' : 'N') << endl;
}