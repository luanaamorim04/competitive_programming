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

int N, MIN, MAX, psa[MAXN], p[MAXN], soma, atual;

int main()
{_  
    cin >> N >> MIN >> MAX;
    for (int i = 1; i <= N; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }

    for (int i = 1; i <= N; i++)
        cin >> p[i];

    int ini = 1, fim = 1;
    atual = p[1];
    soma = -INF;
    while (ini <= fim)
    {
        if (atual > MAX)
        {
            atual -= p[ini];
            ini++;
        }  
        else if (atual < MIN)
        {
            fim++;
            atual += p[fim];
        } 
        else
        {
            if (psa[ini] - psa[ini - 1] < 0)
            {
                atual -= p[ini];
                ini++;
            }

            soma = max(soma, psa[fim] - psa[ini - 1]);
            fim++;
            atual += p[fim];
        }

        if (fim > N)
        {
            fim--;
            atual -= p[ini];
            ini++;
        }  
    }

    cout << soma << endl;
}