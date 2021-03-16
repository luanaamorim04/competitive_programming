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

int n, m, arr[10001], t;

int main()
{_  
    while (cin >> n >> m && n)
    {
        m--;
        int menor = INF, maior = -INF, k = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            k += arr[i];
            if (i >= m)
            {
                menor = min(menor, k);
                maior = max(maior, k);
                k -= arr[i - m];
            }
        }
        ++m;
        cout << "Teste " << ++t << endl;
        cout << (menor / m) << ' ' << (maior / m) << endl << endl;
    }
}