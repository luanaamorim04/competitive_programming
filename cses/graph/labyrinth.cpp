#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int tab[1009][1009], n, m, k;
char c;
par ini, fim;
queue<par> fila;
string ans;
map<par, par> pai;

void res(par a)
{
    if (a == ini) return;
    res(pai[a]);
    if (pai[a].first == a.first + 1) ans += 'U';
    else if (pai[a].first == a.first - 1) ans += 'D';
    else if (pai[a].second == a.second - 1) ans += 'R';
    else if (pai[a].second == a.second + 1) ans += 'L';
}

int main()
{_  
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == 'B') 
            {
                fim = par(i, j);
                tab[i][j] = 2;
            }
            else tab[i][j] = (c == '#' ? 0 : 1);
            if (c == 'A') ini = par(i, j);
        }

    fila.push(ini);
    while (!fila.empty())   
    {
        int a = fila.front().first, b = fila.front().second; fila.pop();
        if (tab[a][b] == 2) 
        {
            k = 1;
            break;
        }
        if (!tab[a][b]) continue;
        tab[a][b] = 0;
        if (tab[a + 1][b])
        {
            fila.push(par(a + 1, b));
            pai[par(a + 1, b)] = par(a, b);
        }
        if (tab[a - 1][b])
        {
            fila.push(par(a - 1, b));
            pai[par(a - 1, b)] = par(a, b);
        }
        if (tab[a][b + 1])
        {
            fila.push(par(a, b + 1));
            pai[par(a, b + 1)] = par(a, b);
        }
        if (tab[a][b - 1])
        {
            fila.push(par(a, b - 1));
            pai[par(a, b - 1)] = par(a, b);
        }
    }

    if (k)
    {
        res(fim);
        cout << "YES\n" << ans.size() << endl << ans << endl;
    }
    else
        cout << "NO\n";
}