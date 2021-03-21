#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <cstring>
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int tot, c, k, x, memo[21][201], t;
vector<int> coisas[21];

int f(int idx, int soma)
{
    if (soma < 0) return -INF;
    if (idx == c) return 0;
    if (~memo[idx][soma]) return memo[idx][soma];
    int ans = -INF;
    for (int i = 0; i < coisas[idx].size(); i++)
        ans = max(ans, f(idx + 1, soma - coisas[idx][i]) + coisas[idx][i]);

    return memo[idx][soma] = ans;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> tot >> c;
        for (int i = 0; i < c; i++)
        {
            coisas[i].clear();
            cin >> k;
            while (k--)
            {
                cin >> x;
                coisas[i].push_back(x);
            }
        }

        memset(memo, -1, sizeof(memo));
        int ans = f(0, tot);
        if (ans < 0) cout << "no solution" << endl;
        else cout << ans << endl;
    }
}