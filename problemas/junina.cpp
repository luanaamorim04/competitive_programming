#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x, ans, n_pode, tmp, t, passou, n_ok;
vector<int> p[22];

int main()
{_
    while (cin >> n && n)
    {
        if (t) cout << endl;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            p[i].clear();
            while (cin >> x && x) p[i].push_back(x - 1);
        }

        for (int i = 0; i < (1<<n); i++)
        {
            n_ok = passou = tmp = n_pode = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if ((i & (1<<j)) && !(n_pode & (1<<j)))
                {
                    passou |= (1<<j);
                    tmp++;
                    for (int k = 0; k < p[j].size(); k++)
                    {
                        if (passou & (1<<p[j][k])) n_ok = 1;
                        n_pode |= (1<<p[j][k]);
                    }
                }
            }

            if (!n_ok) ans = max(ans, tmp);
        }

        cout << "Teste " << ++t << endl << ans << endl;
    }
}