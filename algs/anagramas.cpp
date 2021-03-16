#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD (int) (1000000007)
#define ll long long

using namespace std;

ll letras[260], fact[1000009], ans, i;
string s;

ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}

int main()
{_
    fact[0] = 1;
    for (i = 1; i < 1000009; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    while (cin >> s)
    {
        if (s[0] == '0') return 0;

        ans = fact[s.size()] % MOD;

        for (int i = 0; i < s.size(); i++)
        {
            letras[s[i]]++;
        }

        for (int i = 'a'; i <= 'z'; i++)
        {
            ans = (ans * inv(fact[letras[i]], MOD)) % MOD;
            letras[i] = 0;
        }

        cout << ans << endl;
    }
}