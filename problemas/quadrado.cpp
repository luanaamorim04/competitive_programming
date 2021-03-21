#include <iostream>
#include <set>

using namespace std;

long long q[1009][1009], ideal, linhas, colunas, d, n, x, pode;
set<int> s;

int main()
{
    cin >> n;
    pode = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> q[i][j];
            ideal += q[i][j];
            x = s.size();
            s.insert(q[i][j]);
            if (s.size() == x) pode = 0;
        }
    }

    ideal /= n;
    
    for (int i = 0; i < n; i++)
    {
        linhas = 0;
        colunas = 0;
        d = 0;

        for (int j = 0; j < n; j++)
        {
            linhas += q[i][j];
            colunas += q[j][i];
            d += q[n - 1 - j][j];
        }

        if (linhas != ideal || colunas != ideal || d != ideal)
            pode = false;
    }

    if (pode == true)
        cout << ideal;
    else 
        cout << 0;

    cout << endl;
}