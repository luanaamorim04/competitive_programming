#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, menor, maior, x, t;

struct jogador
{
    int pts, c;
    string nome;
};

jogador gamers[1009];

int cmp(jogador a, jogador b)
{
    if (a.pts > b.pts) 
    {
        return 1;
    }
    else if (a.pts < b.pts)
    {
        return 0;
    }
    return a.nome < b.nome;
}

int main()
{_
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> gamers[i].nome;
            gamers[i].pts = 0;
            menor = 1000009; maior = 0;
            for (int j = 0; j < 12; j++)
            {
                cin >> x;
                gamers[i].pts += x;
                menor = min(menor, x);
                maior = max(maior, x);
            }

            gamers[i].pts -= (menor + maior);
        }

        sort(gamers, gamers+n, cmp);
        gamers[0].c = 1;
        for (int i = 1; i <= n; i++)
        {
            if (gamers[i].pts == gamers[i - 1].pts) gamers[i].c = gamers[i - 1].c;
            else gamers[i].c = i + 1;
        }

        cout << "Teste " << ++t << endl;
        for (int i = 0; i < n; i++)
        {
            cout << gamers[i].c << ' ' << gamers[i].pts << ' ' << gamers[i].nome << endl;
        }
        cout << endl;
    }
}