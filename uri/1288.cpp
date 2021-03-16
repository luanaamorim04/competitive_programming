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

int t, n, p[55], v[55], peso, r, dp[101];

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> v[i] >> p[i];

        cin >> peso >> r;

        for (int i = 0; i <= peso; i++)
            dp[i] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = peso; j >= p[i]; j--)
                dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
        
        if (dp[peso] >= r)
            cout << "Missao completada com sucesso" << endl;
        else 
            cout << "Falha na missao" << endl;
    }
}