#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 10009
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, q, a, b, pai[MAX], maxn[MAX], tam[MAX], p[MAX];
string s, A, B;
map<string, int> mapa;

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (tam[a] > tam[b])
    {
        int tmp = a; a = b; b = tmp;
    }
    pai[a] = b;
    tam[b] += tam[a]; 
    maxn[b] = max(maxn[a], maxn[b]);
}   

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> p[i];
        maxn[i] = p[i];
        mapa[s] = i;
        pai[i] = i;
        tam[i] = 1;
    }
    
    for (int i = 1; i <= m; i++)
    {
        cin >> A >> B;
        a = id(mapa[A]), b = id(mapa[B]);
        join(a, b);
    }
    
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        a = id(mapa[s]);
        if (tam[a] == 1 || maxn[a] <= 5 || p[mapa[s]] >= 5) cout << "S\n";
        else cout << "N\n";
    }
}