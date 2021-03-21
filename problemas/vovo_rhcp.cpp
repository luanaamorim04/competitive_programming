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

int tab[1009][1009], n, m, x, y, a, b, t;

int main()
{_
    while (cin >> n >> m && n)
    {
        a = 0, b = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> tab[i][j];

        while (cin >> x >> y && x || y)
        {
            a += x, b += y;
        }
        a *= -1;
        cout << "Teste " << ++t << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                x = (i + (b % n) + n) % n;
                y = (j + (a % m) + m) % m;
                cout << tab[x][y] << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }   

}