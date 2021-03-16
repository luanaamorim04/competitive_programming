#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, passou[505][505];
char tab[505][505];
vector<par> v;

void flood(int a, int b)
{
    if (!passou[a][b]) return;
    passou[a][b] = 0;
    if (tab[a][b] == '#')
    {
        flood(a - 1, b + 1);
        flood(a - 1, b - 1);
        return;
    }

    tab[a][b] = 'o';
    flood(a + 1, b);
}

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tab[i][j];
            passou[i][j] = 1;
            if (tab[i][j] == 'o')
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        flood(v[i].first, v[i].second);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << tab[i][j];
        }

        cout << endl;
    }
}