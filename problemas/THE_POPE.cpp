#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
map<par, int> mapa;
struct caixa
{
    int p, r;
};
caixa caixas[1009];

int cmp(caixa a, caixa b)
{
    return a.r > b.r;
}

int f(int k, int peso)
{
    if (peso < 0) return -INF;
    if (k == n) return 0;
    if (mapa.count(make_pair(k, peso))) return mapa[make_pair(k, peso)];
    return mapa[make_pair(k, peso)] = max(f(k+1, peso), f(k+1, min(peso, caixas[k].r) - caixas[k].p) + 1);;
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> caixas[i].p >> caixas[i].r;

    sort(caixas, caixas+n, cmp);
    cout << f(0, INF) << endl;
}