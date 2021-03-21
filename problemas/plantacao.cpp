#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, k, soma, total, x, ans;
map<long long, long long> mapa;
char c;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        mapa[k]++;
        total += k;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        c == 'C' ? soma++ : soma--;
        x = mapa[-soma];
        if (x)
        {
            total -= (x*-soma);
            m -= x;
            mapa[-soma] = 0;
        }

        ans += total + (m*soma);
    }

    cout << ans << endl;
}