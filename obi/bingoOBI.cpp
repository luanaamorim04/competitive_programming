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

int n, k, u, bingo[1009], x, ok, i, j, aux, winner[1009];
vector<int> lista[10009];

int main()
{_
    cin >> n >> k >> u;
    for (i = 1; i <= n; i++)
    {
        bingo[i] = k;
        for (j = 1; j <= k; j++)
        {
            cin >> x;
            lista[x].push_back(i);
        }
    }

    for (i = 0; i < u; i++)
    {
        cin >> x;
        if (ok) continue;
        
        for (j = 0; j < lista[x].size(); j++)
        {
            aux = lista[x][j];
            bingo[aux]--;
            if (!bingo[aux]) 
                winner[ok++] = aux;
        }
    }

    sort(winner, winner+ok);

    for (int i = 0; i < ok; i++)
        cout << winner[i] << ' ';

    cout << endl;
}