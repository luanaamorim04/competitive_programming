#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string s;
vector<int> v;

int n, a, indexx;

int main()
{_
    a = 1;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        n = n + ((s[i] - '0') * a / 2);
        a = (a * 10);
        if (i) cout << n;
    }

    while (n > 0)
    {
        v.push_back(n % 2);
        n /= 2;
    }

    for (int i = v.size(); i >= 0; i--)
        cout << v[i];

}