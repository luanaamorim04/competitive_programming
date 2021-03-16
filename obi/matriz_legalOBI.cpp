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

int n, m, tab[1001][1001], b[1001][1001], resp, esq[1001], dir[1001];

int histograma(int linha)
{   
    int resp = 0;
    b[linha][0] = -1, b[linha][m] = -1;
    for (int i = 1; i < m; i++)
    {
        esq[i] = i - 1;
        while (b[linha][esq[i]] >= b[linha][i]) esq[i] = esq[esq[i]];
    }

    for (int i = m - 1; i >= 1; i--)
    {
        dir[i] = i + 1;
        while (b[linha][dir[i]] >= b[linha][i]) dir[i] = dir[dir[i]];
    }

    for (int i = 1; i < m; i++)
    {
        resp = max(resp, (dir[i] - esq[i]) * (b[linha][i] + 1));
    }

    return resp;
}

int legal(int i, int j)
{
    return (tab[i][j] + tab[i - 1][j - 1] <= tab[i][j - 1] + tab[i - 1][j]);
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            if (i && j && legal(i, j)) 
                b[i][j] = 1 + b[i - 1][j];
        }

    for (int i = 1; i < n; i++)
        resp = max(resp, histograma(i));

    cout << (resp != 2 ? resp : 0) << endl;
}