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

int t, n, v[1001], p[1001], dp[5015], peso[5105], tot[5501];

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> v[i] >> p[i];

        for (int i = 1; i < 55; i++)
        {
            dp[i] = 0;
            peso[i] = 0;
            tot[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 50; j >= p[i]; j--)
            {
                if (dp[j] < dp[j - p[i]] + v[i])
                {
                    dp[j] = dp[j - p[i]] + v[i];
                    tot[j] = tot[j - p[i]] + 1;
                    peso[j] = peso[j - p[i]] + p[i];
                }
            }
        }

        cout << dp[50] << " brinquedos" << endl;
        cout << "Peso: " << peso[50] << " kg" << endl;
        cout << "sobra(m) " << n - tot[50] << " pacote(s)" << endl << endl;
    }
}