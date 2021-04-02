#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, psa[200001], base, ans;
string s;
map<int, int> freq;

int main()
{_
    cin >> s;
    freq[0] = 1;
    base = 1;
    n = s.size();
    for (int i = n; i > 0; i--)
    {
        psa[i] = s[i - 1] - '0';
        psa[i] = (psa[i] * base) % 2019;
        base = (base * 10) % 2019;
    }

    for (int i = 1; i <= n; i++)
    {
        psa[i] = (psa[i] + psa[i - 1]) % 2019;
        ans += freq[psa[i]];
        freq[psa[i]]++;
    }

    cout << ans << endl;
}