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
#define INVALID -90
#define curinga_pode 333
#define curinga_n_pode 999
#define par pair<int, int>
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, player, menor, pass, cards[15][1000], ok;
map<char, int> val;
char c;

int is_winner(int player)
{
    for (int i = 1; i <= 13; i++) // ver se ganhou
        if (cards[player][i] != 4 && cards[player][i]) return 0;
    
    return (!cards[player][curinga_pode] && !cards[player][curinga_n_pode]);
}

int main()
{_
    cin >> n >> k;
    val['A'] = 1;
    val['2'] = 2;
    val['3'] = 3;
    val['4'] = 4;
    val['5'] = 5;
    val['6'] = 6;
    val['7'] = 7;
    val['8'] = 8;
    val['9'] = 9;
    val['D'] = 10;
    val['Q'] = 11;
    val['J'] = 12;
    val['K'] = 13;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> c;
            cards[i][val[c]]++;
        }
    }

    player = k;
    cards[player][curinga_n_pode]++;

    while (1)
    {
        if (cards[player][curinga_pode]) 
        {
            cards[player][curinga_pode] = 0;
            pass = curinga_n_pode;
        }
        else
        {
            menor = INF;
            for (int i = 1; i <= 13; i++) // escolher a carta pra dar
            {
                if (cards[player][i] < menor && cards[player][i])
                {
                    menor = cards[player][i];
                    pass = i;
                }
            }

            cards[player][pass]--; // tirar a carta do baralho
        }   
        
        //cout << endl << "pass: " << pass << endl << endl;

        if (cards[player][curinga_n_pode]) 
        {
            cards[player][curinga_n_pode] = 0;
            cards[player][curinga_pode] = 1;
        }

        if (is_winner(player)) 
        {
            cout << player << endl;
            return 0;
        }

        player = (player + 1) % n; // trocar jogador
        if (!player) player = n; 

        cards[player][pass]++; // adicionar carta no baralho do novo jogador
    }
}