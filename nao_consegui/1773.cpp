#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, pode[1001], passou[1001], a, b;
map<int, vector<int> > chave;
set<int> tmp;

int main()
{_
    passou[1] = 1;
    
    while (cin >> n >> m)
    {
        vector<int> grafo[1001];
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }   

        for (int i = 2; i <= n; i++)
        {
            cin >> a;
            chave[a].push_back(i);
            passou[i] = 0;
            pode[i] = 0;
        }

        queue<int> fila;
        int ans = 0, k = 1, h;
        while (k)
        {
            ans = 0;
            k = 0;
            fila.push(1);
            while (!fila.empty())
            {
                int f = fila.front(); fila.pop();
                ans++;
                h = tmp.size();
                tmp.insert(f);
                if (h != tmp.size()) k = 1;

                for (int i = 0; i < chave[f].size(); i++)
                    pode[chave[f][i]] = 1;

                for (int i = 0; i < grafo[f].size(); i++)
                {
                    int g = grafo[f][i];
                    if (pode[g] && !passou[g])
                    {
                        fila.push(g);
                        passou[g] = 1;
                    }
                }
            }
        }

        cout << (ans == n ? "nao\n" : "sim\n");
        chave.clear(); 
    }
}