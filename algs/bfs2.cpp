#include <iostream>
#include <queue>

using namespace std;

int origem, dest, n, nao_pode[100009], x, ans;
queue<pair<int, int> > fila;

int main()
{
    cin >> origem >> dest >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nao_pode[x] = 1;
    }

    ans = -1;
    fila.push(make_pair(origem, 0));
    while (!fila.empty())
    {
        int f = fila.front().first, nivel = fila.front().second; fila.pop();
        if (nao_pode[f] == 1) continue;
        if (f == dest) ans = nivel;
        nao_pode[f] = 1;
        fila.push(make_pair(f + 1, nivel + 1)); 
        fila.push(make_pair(f - 1, nivel + 1)); 
        fila.push(make_pair(f * 2, nivel + 1)); 
        fila.push(make_pair(f * 3, nivel + 1)); 
        if (f % 2 == 0) fila.push(make_pair(f / 2, nivel + 1)); 
    }

    cout << ans << endl;
}