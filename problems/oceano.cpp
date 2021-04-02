#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define MOD 131071

using namespace std;

string s, tmp;
long long num, a, i, sz;

int main()
{_
    while (cin >> tmp)
    {
        s += tmp;
        sz = s.size();
        if (s[sz - 1] == '#')
        {
            //if (a) cout << '\n';
            num = 0, a = 1;
            for (i = sz - 2; i > -1; i--)
            {
                if (s[i] - '0') num = (num % MOD) + (a % MOD) % MOD;
                a = (a * 2) % MOD;
            }

            if (num % MOD == 0) cout << "YES\n";
            else cout << "NO\n";
            s = "";
        }
    }
}