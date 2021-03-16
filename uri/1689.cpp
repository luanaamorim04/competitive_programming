#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a[1000006], k, t, N, memo[1000006], pos[1000009];

int bb(int x, int ini)
{
    int meio, fim = N + 1;
    while (ini <= fim)
    {
        meio = ini + (fim - ini)/2;
        if (x <= pos[meio])
        {
            fim = meio - 1;
        }
        else
        {
            ini = meio + 1;
        }
    }

    return fim + 1;
}

int f(int n, int start)
{
    int x = bb(n, start);
    if (pos[x] == INF) return 0;
    if (memo[pos[x]] != -1) return memo[pos[x]];
    return memo[pos[x]] = max(a[x] + f(pos[x] + k, x + 1), f(pos[x + 1], x + 1));
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> N >> k;
        for (int i = 1; i <= N; i++)
        {
            cin >> pos[i];
            memo[pos[i]] = -1;
        }
        pos[N + 1] = INF;

        for (int i = 1; i <= N; i++)
        {
            cin >> a[i];
        }

        cout << f(1, 1) << endl;
    }
}