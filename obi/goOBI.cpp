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

int n, tab[505][505], p, a, b, psa[505][505], preta[505][505], preto, branco;

int main()
{_
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        tab[a][b] = 1;
        preta[a][b] = 1;
    }
    while (p--)
    {
        cin >> a >> b;
        tab[a][b] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + tab[i][j];
            preta[i][j] += preta[i - 1][j] + preta[i][j - 1] - preta[i - 1][j - 1];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= n; j++)
            {
                int total = psa[i][j] - psa[i - k][j] - psa[i][j - k] + psa[i - k][j - k];
                int pt = preta[i][j] - preta[i - k][j] - preta[i][j - k] + preta[i - k][j - k];
                if (total == pt && pt) preto++;
                else if (total < 0 && !pt) branco++;
            }
        }
    }

    cout << preto << ' ' << branco << endl;
}