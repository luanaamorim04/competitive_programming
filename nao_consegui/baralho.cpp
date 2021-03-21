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

char c;
int N, K, freq[15], coringa[15], turn, pass, next_p, val[100], x;
vector<int> cards[15];

int is_winner(int player);
int give(int player);

int main()
{_  
    val['A'] = 1 + '0'; val['D'] = 10 + '0'; val['Q'] = 11 + '0'; val['J'] = 12 + '0'; val['K'] = 13 + '0';
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> c;
            x = (val[c] ? val[c] : c) - '0';
            cards[i].push_back(x);
        }
    }

    x = 10;
    coringa[K] = -1;
    turn = K;
    while (x--)
    {
        is_winner(turn);
        next_p = ((turn + 1) % N != 0 ? (turn + 1) % N : N); 
        if (coringa[turn] == 1) 
        {
            coringa[turn] = 0;
            coringa[next_p] = -1;
            continue;
        }
        else if (coringa[turn] == -1) 
        {
            coringa[turn] = 1;
        }

        cards[next_p].push_back(cards[turn][cards[turn].size() - 1]);
        cards[turn].pop_back();
        turn = next_p;
    }
}

int give(int player)
{
    int freq[]
    for (int i = 0; i < cards[player].size(); i++)
    {
        
    }
}

int is_winner(int player)
{
    for (int i = 0; i < cards[player].size(); i++)
    {
        
    }
}