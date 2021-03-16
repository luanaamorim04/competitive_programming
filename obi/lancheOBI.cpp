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

int n, m, soma[300][300], ans, a, b, c;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            soma[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        soma[a][b] = c;
        soma[b][a] = c;
    }

    ans = INF;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                soma[i][j] = min(soma[i][k] + soma[k][j], soma[i][j]);

    

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        soma[i][i] = 0;
        for (int j = 1; j <= n; j++)
            tmp = max(tmp, soma[i][j]);
        
        ans = min(ans, tmp);
    }


    cout << ans << endl;
}