#include <iostream>
#include <algorithm>
using namespace std;

struct Hora
{
    int inicio, fim;
};

int main()
{
    int n, horario_safe;
    Hora consulta[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> consulta[i].inicio >> consulta[i].fim;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (consulta[i].fim > consulta[j].fim)
            {
                Hora temp = consulta[j];
                consulta[j] = consulta[i];
                consulta[i] = temp;
            }
        }
    }
    

    int fim = 0, counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (consulta[i].inicio >= fim)
        {
            fim = consulta[i].fim;
            counter++;
        }
    }

    cout << counter << "\n";


}