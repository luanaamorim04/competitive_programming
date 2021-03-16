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

int n, m, saldo[1000009], ans, a1;

int main()
{_
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        cin >> a >> v >> b;
        saldo[a] -= v;
        saldo[b] += v;
        a1 += v;
    }

    for (int i = 1; i <= n; i++)
    {
        if (saldo[i] > 0) ans += saldo[i];
    }

    cout << (ans == a1 ? "N" : "S") << endl;
    cout << ans << endl;
}