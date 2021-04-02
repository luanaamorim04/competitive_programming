#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int g, p, s, k, ava[101][101]; // variaveis

struct Piloto // cada piloto tem 1 id, 1 ponto e g posicoes
{
    int id, pontos, pos[101];
};

int main()
{
    while (true)
    {
        cin >> g >> p;
        if (g == 0 && p == 0)
            return 0;

        memset(ava, 0, sizeof(ava)); 
        Piloto pilotos[p]; // um array com todos os pilotos 

        // dar uma id para cada piloto de 1 ate p na ordem crescente 
        for (int i = 0; i < p; i++)
        {
            pilotos[i].pontos = 0;
            pilotos[i].id = i + 1;
        }

        // informar a posicao de cada piloto para cada uma das g corridas
        for (int i = 0; i < g; i++)
            for (int j = 0; j < p; j++)
            {
                int temp;
                cin >> temp;
                pilotos[j].pos[i] = temp - 1;
            }

        // input dos pontos a atribuir
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
                cin >> ava[i][j];
        }
                    
        for (int h = 0; h < s; h++)
        {
            // fazer o update dos pontos de cada piloto para cada sistema de pontuacao
            for (int i = 0; i < g; i++)
                for (int j = 0; j < p; j++)
                    pilotos[j].pontos += ava[h][pilotos[j].pos[i]];

            // fazer um sort dos pilotos de acordo com sua pontuacao para cada sistema diferente
            Piloto a;
            a.pontos = 0;
            for (int i = 0; i < p; i++)
                if (a.pontos < pilotos[i].pontos)
                    a.pontos = pilotos[i].pontos;

            // imprimir o vencedor
            cout << "\n";
            for (int e = 0; e < p; e++)
            {
                if (a.pontos == pilotos[e].pontos)
                    cout << pilotos[e].id << " ";

                pilotos[e].pontos = 0;
            }
        }
    
    }

}