#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1300031LL
#define MAX (int) (2e6 + 5)

using namespace std;

long long n, k, fat[MAX], t, inv[MAX], ans;

long long inv_mod(long long a, long long b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

int main()
{_
    fat[0] = 1;
    for (int i = 1; i < MAX - 1; i++)
    {
        fat[i] = (fat[i - 1]*i) % MOD;
        inv[i] = inv_mod(fat[i], MOD);
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ans = fat[n + k - 1];
        ans = (ans * inv[n - 1]) % MOD;
        ans = (ans * inv[k]) % MOD;
        cout << ans << endl;
    }

    return 0;
}