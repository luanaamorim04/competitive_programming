#include <iostream>
#include <vector>
using namespace std;

int MAX = 20;

struct Carta
{
    int num;
    char naipe;
};

struct Lucas
{
    bool istrue;
    Carta x;
};

struct Player
{
    int id, n_cartas;
    vector<Carta>cartas;
};

int p, m, n, ini = 0;

Lucas achar_o_maior(Player cuzao, string s, Carta ref);

int main()
{
    string game_state = "play";
    cin >> p >> m >> n;
    do
    {
        cin >> p >> m >> n;
        Carta saque;
        vector<Player>pessoa(p);
        vector<Carta>baralho(n);
        for (int i = 0; i < n; i++)
        {
            Carta a;
            cin >> a.num >> a.naipe;
            baralho.push_back(a);
        }

        for (int i = 0; i < p; i++)
        {
            pessoa[i].id = i + 1;
            pessoa[i].n_cartas = m;
            for (int j = ini; j < m; j++)
            {
                pessoa[i].cartas.push_back(baralho[sizeof(baralho) - 1]);
                baralho.pop_back(); 
            }
            ini += m;
        }

        saque = baralho[sizeof(baralho)  - 1];
        baralho.pop_back();

        while (game_state == "play")
        {
            for (int i = 0; i < p; i++)
            {
                bool descarte = false;
                Lucas aaa = achar_o_maior(pessoa[i], "num", saque);
                Lucas bbb = achar_o_maior(pessoa[i], "naipe", saque);
                if (aaa.istrue == true)
                {
                    descarte = true;
                    pessoa[i].cartas.pop_back();
                    pessoa[i].n_cartas -= 1;
                    saque = aaa.x;
                }
                else  if (bbb.istrue == true)
                {
                    descarte = true;
                    pessoa[i].cartas.pop_back();
                    pessoa[i].n_cartas -= 1;
                    saque = bbb.x;
                }
            }
        }





    } while (p != 0 && m != 0 && n != 0);
}

Lucas achar_o_maior(Player cuzao, string s, Carta ref)
{
    if (s == "num")
    {
        int maior = 0, index;
        for (int j = 0; j < cuzao.n_cartas; j++)
        {
            if (maior < cuzao.cartas[j].num && cuzao.cartas[j].naipe == ref.naipe)
            {
                maior = cuzao.cartas[j].num;
                index = j;
            }
        }

        Carta temp = cuzao.cartas[index];
        cuzao.cartas[index] = cuzao.cartas[cuzao.n_cartas - 1];
        cuzao.cartas[cuzao.n_cartas - 1] = temp;
        Lucas pires;
        if (maior != 0)
            pires.istrue = true;
        else 
            pires.istrue = false;
        pires.x = cuzao.cartas[cuzao.n_cartas - 1];
        return pires;
    }
    else
    {
        Carta melhor;
        int maior = 0, index;
        for (int j = 0; j < cuzao.n_cartas; j++)
        {
            if (cuzao.cartas[j].num == ref.num && maior < cuzao.cartas[j].naipe)
            { 
                maior = cuzao.cartas[j].naipe;
                index = j;
            }
        }

        Carta temp = melhor;
        melhor = cuzao.cartas[cuzao.n_cartas - 1];
        cuzao.cartas[cuzao.n_cartas - 1] = temp;
        Lucas pires;
        if (maior != 0)
            pires.istrue = true;
        else 
            pires.istrue = false;
        pires.x = melhor;
        return pires;
    }
    
}