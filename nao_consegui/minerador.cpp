#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, lucro[10004], menor, maior, a1, a2, dia[10009];

int main()
{_
    cin >> n;
    menor = INF;
    for (int i = 1; i <= n; i++)
    {
        cin >> lucro[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> dia[i];
        dia[i] += dia[i - 1];
        lucro[i] *= dia[i];
        if (menor > lucro[i])
        {
            menor = lucro[i];
            a1 = i;
        }
        if (maior < lucro[i])
        {
            maior = lucro[i];
            a2 = i;
        }
    }

    cout << a1 << ' ' << maior << endl << a2 << ' ' << menor << endl;
}