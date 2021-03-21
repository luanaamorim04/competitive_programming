#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t[3];  
    cin >> t[0] >> t[1] >> t[2]; 
    for (int i = 0; i < 3; i++)
    {
        int soma = 0;

        // caso 1: se dois sao iguais
        for (int j = 0; j < 3; j++)
        {
            if (t[i] == t[j] && i != j)
            {
                cout << 'S' << endl;
                return 0;
            }
            if (i != j)
                soma += t[j];
        }

        // caso 2: se a soma de 2 e igual a 1
        if (soma == t[i])
        {
            cout << 'S' << endl;
            return 0;
        }
    }  

    cout << 'N' << endl;
}