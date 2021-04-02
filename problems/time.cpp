#include <iostream>

using namespace std;

struct player
{
    string name;
    int hab;
};

int main()
{
    player jo[10002];
    string nomes[10000];
    int n, t, index = 0;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> jo[i].name >> jo[i].hab;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (jo[i].hab < jo[j].hab)
            {
                player t = jo[i];
                jo[i] = jo[j];
                jo[j] = t;
            }
        }
    
    for (int i = 0; i < t; i++)
    {
        index = 0;
        cout << "Time " << i + 1 << endl;
        for (int j = i; j < n; j+= t)
        {
            nomes[index] = jo[j].name;
            index++;
        }

        for (int k = 0; k < index; k++)
            for (int h = k + 1; h < index; h++)
            {
                if (nomes[k] > nomes[h])
                {
                    string temp = nomes[k];
                    nomes[k] = nomes[h];
                    nomes[h] = temp;
                }
            }

        for (int k = 0; k < index; k++)
            cout << nomes[k] << endl;

        cout << endl;
    }

}