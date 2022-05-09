#include <iostream>

using namespace std;

int b[200009], g[200009], t, n, a, o, x, pa[200009], pb[200009];
long long ans;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> o >> n;
        ans = 0;
        for (int i = 1; i <= max(a, o); i++)
            g[i] = 0, b[i] = 0;
        
        for (int i = 0; i < n; i++)
        {
            cin >> pa[i];
            g[pa[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> pb[i];
            b[pb[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            ans += (n - (g[pa[i]] + b[pb[i]])) + 1;
        }

        cout << ans / 2 << endl;
    }
}