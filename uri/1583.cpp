#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
char tanque[101][101];

void dfs(int a, int b)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (tanque[a][b] == 'Y' || tanque[a][b] == 'X') return;

    tanque[a][b] = 'Y';
     
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
}

int main()
{_
    while (cin >> n >> m && m || n)
    {    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> tanque[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (tanque[i][j] == 'T')
                    dfs(i, j);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << (tanque[i][j] == 'Y' ? 'T' : tanque[i][j]);
            
            cout << endl;
        }

        cout << endl;
    }
}