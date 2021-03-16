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
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long c, t, alvo[MAXN], x, y, ans;

int bb(long long x)
{
    int ini = 0, meio, fim = c - 1;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (alvo[meio] >= x) fim = meio - 1;
        else ini = meio + 1;
    }

    return c - (fim + 1);
}

int main()
{_  
    cin >> c >> t;
    for (int i = 0; i < c; i++)
    {
        cin >> alvo[i];
        alvo[i] *= alvo[i];
    }

    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        long long a = x*x + y*y;
        ans += bb(a);
    }

    cout << ans << endl;
}