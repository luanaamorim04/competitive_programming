#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, k, x, ans, dias;
priority_queue<par, vector<par>, greater<par> > fila;
queue<int> pilha[100009];

long long fast_expo(long long x)
{
    long long a = 1, b = 365LL;
    while (x)
    {
        b = b % MOD;
        a = a % MOD;
        if (x % 2) a = (a * b) % MOD;
        b = (b * b) % MOD;
        x /= 2;
    }

    return a % MOD;
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> x;
            pilha[i].push(x);
            dias++;
        }
        fila.push(make_pair(pilha[i].front(), i));
    }

    while (!fila.empty())
    {
        int f = fila.top().first, i = fila.top().second; fila.pop();
        ans = ans % MOD;
        ans = ans + ((f * fast_expo(dias)) % MOD) % MOD;
        pilha[i].pop();
        if (!pilha[i].empty())
            fila.push(make_pair(pilha[i].front(), i));

        dias--;
    }

    cout << ans % MOD << endl;
}