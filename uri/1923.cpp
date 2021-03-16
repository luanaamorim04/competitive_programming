#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n, c, passou[10000], f, nivel[10000], idx, T;
string a, b, nomes[10000];
map<string, int> id;
vector<int> grafo[10000];
vector<string> ans;

int cmp(string a, string b)
{
    return a < b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (!id[a])
        {
            id[a] = ++idx;
            nomes[idx] = a;
        }   
        if (!id[b])
        {
            id[b] = ++idx;
            nomes[idx] = b;
        } 
        grafo[id[a]].push_back(id[b]);
        grafo[id[b]].push_back(id[a]);
        // cout << a << ' ' << id[a] << endl;
        // cout << b << ' ' << id[b] << endl;
    }

    queue<int> fila;
    f = id["Rerisson"];
    fila.push(f);
    passou[f] = 1;
    while (!fila.empty())
    {
        f = fila.front(); fila.pop();
        if (nivel[f] >= c)
        {
            break;
        }
        
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int g = grafo[f][i];
            if (!passou[g])
            {
                T++;
                passou[g] = 1;
                nivel[g] = nivel[f] + 1;
                fila.push(g);
                ans.push_back(nomes[g]);
            }
        }   
    }

    sort(ans.begin(), ans.end());
    cout << T << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }    
}