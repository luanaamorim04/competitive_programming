#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 100000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, m, memo[1009][1009], a[1009], ta[1009], x;
long long ok;

int f(int ini, int fim)
{
    if (ini == fim) 
    {
        ok = (ok + (!ta[ini])) % MOD;
        return a[ini];
    }
    if (memo[ini][fim] != -1) return memo[ini][fim];
    for (int i = ini; i <= n; i++)
    {
        ans = f(ini+1, )
    }
    int meio = ini + (fim-ini)/2;
    int ans = f(ini, meio)^f(meio+1, fim);
    ok = (ok + (!ta[ans])) % MOD;
    return memo[ini][fim] = ans;
}

int main()
{_
    cin >> t;
    for (int k = 1; k <= t; k++)
    {    
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 1; j <= n; j++)
                memo[i][j] = -1;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> x;
            ta[x] = 1;
        }

        ok = 0;
        f(1, n);
        cout << "Case " << k << ": " << ok % MOD << endl;
    }
}