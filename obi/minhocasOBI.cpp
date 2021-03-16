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
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[109][109], coluna[109], linha, ans;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        linha = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            linha += tab[i][j];
            coluna[j] += tab[i][j];
        }
        ans = max(ans, linha);
    }

    for (int i = 0; i < m; i++)
        ans = max(ans, coluna[i]);

    cout << ans << endl;
}