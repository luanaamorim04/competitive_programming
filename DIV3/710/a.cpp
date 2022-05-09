#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll t, n, m, x, linha, coluna, resp;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x;
        linha = x % (n); if (!linha) linha = n;
        coluna = (x + n - 1)/n;
        resp = (linha - 1)*m;
        resp += coluna;
        cout << resp << endl;
    }
}
