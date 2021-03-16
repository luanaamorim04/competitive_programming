#include <iostream>
#include <vector>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, X, Y, tmp, ini, fim, meio, ans;
vector<int> v;

int main()
{_
    while (cin >> N)
    {
        while (N--)
        {
            cin >> X >> Y;
            for (int i = X; i <= Y; i++)
                v.push_back(i);
        }

        cin >> X;

        sort(v.begin(), v.end());

        ini = 0, fim = v.size() - 1, ans = -1;

        while (ini <= fim)
        {
            meio = ini + ((fim-ini)/2);
            if (v[meio] == X)
            {
                ans = meio;
                fim = meio - 1;
            }
            else if (v[meio] > X)
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
            cout << X << " not found\n";
            v.clear();
            continue;
        }
        else
        {
            cout << X << " found from " << ans << " to ";
        }
        

        ini = ans, fim = v.size() - 1;

        while (ini <= fim)
        {
            meio = ini + ((fim-ini)/2);
            if (v[meio] == X)
            {
                ans = meio;
                ini = meio + 1;
            }
            else if (v[meio] > X)
            {
                fim = meio - 1;
            }
            else
            {
                ini = meio + 1;
            }
        }

        cout << ans << endl;
        v.clear();
    }
}