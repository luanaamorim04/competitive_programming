#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1000090
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, maior, menor, pai[MAX], tam[MAX], total[MAX];

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (a == b) return;
    if (tam[a] > tam[b])
    {
        int tmp = a; a = b; b = tmp;
    }
    total[tam[a]]--; total[tam[b]]--;
    pai[a] = b;
    tam[b] += tam[a]; total[tam[b]]++;
    maior = max(tam[b], maior);
}   

int main()
{_
    cin >> n >> m;
    menor = 1;
    total[1] = n;

    for (int i = 1; i <= n; i++)
    {
        pai[i] = i;
        tam[i] = 1;
    }
    while (m--)
    {
        cin >> a >> b;
        a = id(a), b = id(b);
        join(a, b);
        while (!total[menor])
        {
            menor++;
        }
        cout << maior - menor << endl;
    }
}