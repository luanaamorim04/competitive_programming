#include <iostream>
#include <cstring>

using namespace std;

int n, m, grau[101], counter;

int main()
{
    while (cin >> n >> m && n)
    {
        int maior = 0, e, f;
        memset(grau, 0, sizeof(grau));
        
        while (m--)
        {
            cin >> e >> f;
            grau[e]++;
            grau[f]++;
        }

        for (int i = 1; i <= n; i++)
            maior = max(maior, grau[i]);

        cout << "Teste " << ++counter << "\n";

        for (int i = 1; i <= n; i++)
            if (grau[i] == maior)
                cout << i << ' ';
           
        cout << "\n\n";
    }
}