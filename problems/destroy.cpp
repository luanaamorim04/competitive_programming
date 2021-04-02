#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, pai[100009], tam[100009], x;
long long soma[100009], tmp, v[100009];
stack<long long> pilha, ans;

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    a = id(a), b = id(b);
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
    soma[b] += soma[a]; 
}

int main()
{_

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pai[i] = -1;
        tam[i] = 1;
        soma[i] = v[i];
    }

    pai[0] = -1; pai[n + 1] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pilha.push(x);
    }

    ans.push(0);

    while (!pilha.empty())
    {
        int p = pilha.top(); pilha.pop();
        pai[p] = p;

        if (pai[p - 1] != -1)
            join(p, p - 1);
        if (pai[p + 1] != -1)
            join(p, p + 1);

        tmp = max(tmp, soma[id(p)]);

        ans.push(tmp);
    }

    ans.pop();

    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }

}