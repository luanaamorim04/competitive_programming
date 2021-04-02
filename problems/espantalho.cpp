#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[1009][1009], soma[1009][1009], ans;

int main()
{_
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tab[i][j];
            soma[i][j] = soma[i - 1][j] + soma[i][j - 1] - soma[i - 1][j - 1] + tab[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a = soma[i][j]; 
            int b = soma[i][m] - a;
            int c = soma[n][j] - a; 
            int d = soma[n][m] - (a + b + c);

            if (a == b && a == c && a == d)
            {
                ans = 1;
                cout << i << ' ' << j << endl;
            }
        }
    }

    if (!ans) cout << -1 << endl;
}