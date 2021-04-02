#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD (int) (1e9 + 7)

using namespace std;

string s;
long long ans, a, r;
int zero, atual, len, i;

int main()
{_
    cin >> s;
    ans = 1;
    r = 1;
    len = s.size() - 1;
    for (i = 0; i < len; i++)
    {
        if (s[i] == 'M') --atual;
        else ++atual;

        if (!atual)
        {
            if (zero) r = (r * 2) % MOD;
            ++zero;

            ans = (ans + r) % MOD;
        }
    }

    cout << ans << endl;
}