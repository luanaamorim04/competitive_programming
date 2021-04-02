#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define MOD (ll) 1000000007

using namespace std;

ll psa[51][51], fact[2510], ans;
char c;

int n, m, a1, a2, b1, b2, livre, total, parede, i, j;

ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}

int main()
{_
    fact[0] = 1;
    for (i = 1; i < 2510; i++)
    {
        fact[i] = ((fact[i - 1] % MOD) * i) % MOD;
    }   

    cin >> n >> m;
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            cin >> c;
            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1];
            if (c == '#')
                psa[i][j]++;
        }

    while (cin >> a1 >> b1 >> a2 >> b2)
    {
        total = (a2 - a1 + 1) * (b2 - b1 + 1);
        parede = psa[a2][b2] - psa[a1 - 1][b2] - psa[a2][b1 - 1] + psa[a1 - 1][b1 - 1];
        livre = total - parede;
        ans = fact[total];
        ans = (ans * inv(fact[livre], MOD)) % MOD;
        ans = (ans * inv(fact[parede], MOD)) % MOD;
        
        cout << ((ans - 1 + MOD) % MOD) << endl;
    }
}