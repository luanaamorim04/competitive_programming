#include <iostream>
#define MOD 86400

using namespace std;

long long ans, r, h, m, seg;
string s;

int expo(long long a, long long b)
{
    r = 1;
    while (b)
    {
        if (b%2) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }

    return r;
}

int main()
{
    cin >> s;
    ans = 1;
    for (int i = 0; i < s.size(); i++)
    {
        ans = (expo(ans, 10) * expo(2, s[i] - '0')) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD; 
    seg = ans % 60; ans /= 60;
    m = ans % 60;   ans /= 60;
    h = ans;

    if (h < 10)
        cout << '0';

    cout << h << ':';

    if (m < 10)
        cout << '0';

    cout << m << ':';

    if (seg < 10)
        cout << '0';

    cout << seg << '\n';

}
