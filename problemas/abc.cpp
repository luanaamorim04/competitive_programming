#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

#define MOD 1000000007

using namespace std;

int main()
{_
    string s;
    while (cin >> s)
    {
        long long res = 0, a = 1;
        for (int i = s.size() - 1; i > -1; i--)
        {
            res = res + (s[i] - 65) * (a % MOD) % MOD;
            a = (a * 26) % MOD;
        }

        cout << res % MOD << endl;
    }
}