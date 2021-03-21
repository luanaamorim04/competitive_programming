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
#define MOD 1300031
#define par pair<int, pair<int, int> >
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, a, b, c, ans, id[10009];
vector<par> arestas;

int find(int x)
{
    if (id[x] == x) return x;
    return id[x] = find(id[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    id[a] = id[b];
}

int main()
{_  
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            id[i] = i;
            cin >> a >> b >> c;
            arestas.push_back(par(c, make_pair(a, b)));
            arestas.push_back(par(c, make_pair(a, b)));
        }
        id[n] = n;

        sort(arestas.begin(), arestas.end());

        for (int i = 0; i < arestas.size(); i++)
        {
            a = arestas[i].second.first, b = arestas[i].second.second, c = arestas[i].first;
            if (find(a) == find(b)) continue;
            join(a, b);
            ans = (ans + c) % MOD;
        }

        cout << (ans * 2) % MOD << endl;
        arestas.clear();
        ans = 0;
    }
}