#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int p, n, m, x, player, sentido, regra;
char c;
vector<par> cartas[11], saque;
par descarte;

int cmp(par a, par b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second > b.second;
}

int give_card(int x);
void get_card(int x);
void rules();

int main()
{_  
    while (cin >> p >> m >> n && (n || p || m))
    {
        for (int i = 1; i <= p; i++)
        {
            cartas[i].clear();
            for (int j = 0; j < m; j++)
            {
                cin >> x >> c;
                cartas[i].push_back(make_pair(x, c));
            }
        }
        
        cin >> x >> c;
        descarte = make_pair(x, c);

        saque.clear();
        for (int i = n; i >= p*m + 2; i--)
        {
            cin >> x >> c;
            saque.push_back(make_pair(x, c));
        }

        player = 1, regra = 0, sentido = 1;
        rules();
        while (1)
        {
            if (regra == 2)
            {
                get_card(player);
                get_card(player);
                regra = 0;
            }
            else if (regra == 3)
            {
                get_card(player);
                regra = 0;
            }
            else if (!regra)
            {
                if (give_card(player) == 0)
                {
                    get_card(player);
                    if (give_card(player)) rules();
                }
                else rules();
            }
            else
            {
                regra = 0;
            }

            if (cartas[player].size() < 1) 
            {
                cout << player << endl;
                break;
            }

            if (regra == 1) 
            {
                sentido *= -1;
                regra = 0;
            }
            player = (player + sentido) % p;
            if (!player) player = p;
        }
    }
}

int give_card(int x)
{
    sort(cartas[x].begin(), cartas[x].end());
    for (int i = 0; i <= cartas[x].size(); i++)
    {
        if (cartas[x][i].first == descarte.first || cartas[x][i].second == descarte.second)
        {
            descarte = cartas[x][i];
            cartas[x].erase(cartas[x].begin()+i);
            return 1;
        }
    }
    return 0;
}

void rules()
{
    if (descarte.first == 12) regra = 1;
    else if (descarte.first == 7) regra = 2;
    else if (descarte.first == 1) regra = 3;
    else if (descarte.first == 11) regra = 4;
    else regra = 0;
}

void get_card(int x)
{
    if (saque.size() < 1) return;
    cartas[x].push_back(saque[0]);
    saque.erase(saque.begin()+0);
}   