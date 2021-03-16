#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>

using namespace std;

int n, id, passou[3009], x, y;
string a, b, arr[3009];
map<string, int> mapa;
queue<int> fila;
vector<int> grafo[3009];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < a.size(); j++)
            if (a[j] == '_') a[j] = '-';
        for (int j = 0; j < b.size(); j++)
            if (b[j] == '_') b[j] = '-';

        if (!mapa[a]) 
        {
            mapa[a] = ++id;
            arr[id - 1] = a;
        }
        if (!mapa[b])
        {
            mapa[b] = ++id;
            arr[id - 1] = b;
        } 
        grafo[mapa[a]].push_back(mapa[b]);
    }

    sort(arr, arr+id);

    for (int i = 0; i < id; i++)
    {
        grafo[mapa[arr[i - 1]]].push_back(mapa[arr[i]]);
        grafo[mapa[arr[i]]].push_back(mapa[arr[i - 1]]);
    }

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '_') a[i] = '-';
    for (int i = 0; i < b.size(); i++)
        if (b[i] == '_') b[i] = '-';
    
    fila.push(mapa[a]);
    passou[mapa[a]] = 1;
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!passou[v])
            {
                passou[v] = passou[f] + 1;
                fila.push(v);
            }
        }
    }

    cout << passou[mapa[b]] - 1 << endl;
}