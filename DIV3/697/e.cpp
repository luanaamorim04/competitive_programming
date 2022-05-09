#include <iostream>
#include <algorithm>
#define MOD (int) (1e9 + 7)
#define ll long long

using namespace std;

int t, n, k, p[1009], freq[1009], fs;
ll fat[1001];

ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}

ll escolhe(int a, int b)
{
    ll ans = 1;
    for (int i = 0; i < b; i++)
        ans = (ans * (a - i)) % MOD;

    return ((ans * inv(fat[b], MOD)) % MOD);
}

int main()
{
    fat[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        fat[i] = (fat[i - 1] * i) % MOD;
    }

    cin >> t;
    while (t--)
    {
        fs = 0;
        cin >> n >> k;

        for (int i = 0; i <= n; i++) freq[i] = 0;
    
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            freq[p[i]]++;
        }

        sort(p, p+n);

        for (int i = 1; i <= k; i++)
            if (p[n - i] == p[n - k]) fs++;

        cout << escolhe(freq[p[n - k]], fs) << endl;
    }
}