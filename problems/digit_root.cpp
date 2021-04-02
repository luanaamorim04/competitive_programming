#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string a, b;
long long n, base, digit, ans;

int expo(long long a, long long b)
{
    int r = 1;
    while (b)
    {
        if (b%2) r = (r * a) % 9; 
        a = (a * a) % 9;
        b /= 2;
    }

    return r;
}

int main()
{_
    cin >> a >> b;
    base = 1;
    ans = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        digit = a[i] - '0';
        n = ((n * base) + digit) % 9;
        base = (base * 10) % 9;
    }

    for (int i = 0; i < b.size(); i++)
    {
        digit = b[i] - '0';
        ans = (expo(ans, 10) * expo(n, digit)) % 9;
    }

    cout << (ans ? ans : 9) << '\n';
}