#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> fila;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        fila.push_back(tmp);
    }

    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            if (fila[j] == tmp)
            {
                fila[j] = -1;
                break;
            }
        }
    }

    for (int j = 0; j < n; j++)
        if (fila[j] != -1) cout << fila[j] << ' ';
}