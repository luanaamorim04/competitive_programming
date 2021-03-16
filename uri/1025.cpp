#include <iostream>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, Q, arr[100000], ini, meio, fim, x, ans, caso;

int main()
{_
    while (cin >> N >> Q && N)
    {
        ++caso;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+N);

        cout << "CASE# " << caso << ":\n";

        while (Q--)
        {
            cin >> x;
            ini = 0, fim = N - 1, ans = -1;
            while (ini <= fim)
            {
                meio = ini + ((fim-ini)/2);
                if (arr[meio] == x)
                {
                    ans = meio;
                    fim = meio - 1;
                }
                else if (arr[meio] > x)
                {
                    fim = meio - 1;
                }
                else
                {
                    ini = meio + 1;
                }
            }

            if (ans == -1)
            {
                cout << x << " not found\n";
            }
            else
            {
                cout << x << " found at " << ans+1 << endl;
            }
        }
    }
}