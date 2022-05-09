#include <iostream>
#include <algorithm>

using namespace std;

int ans, n, t, arr[200001], x, tam[200001], comp[200009], k;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            arr[i] = x;
            tam[i] = 0;
            comp[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!comp[i])
            {
                int x = arr[i];
                ++k;
                while (i != x)
                {
                    comp[x] = k;
                    tam[k]++;
                    x = arr[x];
                }
                comp[x] = k;
                tam[k]++;
            }
            cout << tam[comp[i]] << ' ';
        }

        cout << endl;
    }
}