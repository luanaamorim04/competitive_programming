#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pessoa
{
    string nome;
    int pontos, min;
};

int main()
{
    long long n, m, a, b, c;
    vector<pessoa> p;
    cin >> n >> m;

    // entrada
    for (int i = 0; i < n; i++)
    {
        bool add = true;
        string tmp;
        cin >> tmp >> a;
        for (int j = 0; j < p.size(); j++)
        {
            if (tmp == p[j].nome)
            {
                if ((a - p[j].min) >= m)
                {
                    p[j].pontos += 25;
                    p[j].min = a;
                } 
                add = false;
                break;
            }   
        }
        if (add == true)
        {
            pessoa t;
            t.nome = tmp;
            t.min = a;
            t.pontos = 25;
            p.push_back(t);
        }

    }

    // sort
    for (int i = 0; i < p.size(); i++)
        for (int j = i + 1; j < p.size(); j++)
        {
            b = p[i].pontos;
            c = p[j].pontos;
            if (b < c)
            {
                pessoa temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            else if (b == c && p[i].nome > p[j].nome)
            {
                pessoa temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    
    // saida
    cout << "--Rank do Nepscord--" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << '#' << i + 1 << ". ";
        if (i < p.size())
            cout << p[i].nome << " - Nivel " << (p[i].pontos / 100) + 1 << endl;
        else 
            cout << endl;
    }
}