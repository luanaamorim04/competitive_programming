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

double menor, maior, n, val[10009], qnt[10009], k, d, ia, ib;

int main()
{_  
    cin >> n >> k;
    menor = INF;
    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
    {
        cin >> qnt[i];
        d += qnt[i];
        if (menor > d*val[i])
        {
            menor = d*val[i];
            ia = i;
        }
        if (maior < d*val[i])
        {
            maior = d*val[i];
            ib = i;
        }
    }

    cout << ib + 1 << ' ' << fixed << setprecision(2) << k*maior << endl;
    cout << (int) ia + 1<< ' ' << fixed << setprecision(2) << k*menor << endl;
}