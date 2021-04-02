#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF (int) (1e9 + 1)
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, c[MAXN][4];

int f(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i][1] < x)
        {
            ans += (c[i][2] - c[i][0]) * (min(x, c[i][3]) - c[i][1]);
        }
    }

    return ans >= k;
}

int main()
{_  
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3];

    int ini = -INF, fim = INF, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (f(meio)) fim = meio - 1;
        else ini = meio + 1;
    }

    if (fim == INF) cout << "PERDAO MEU REI" << endl;
    else cout << fim + 1 << endl;
}