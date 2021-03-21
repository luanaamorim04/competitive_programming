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

int n, arr[1003], x, m, ok;
map<int, bool> mapa;

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    ok = 1;
    while (m--)
    {
        cin >> x;
        if (!mapa[x] && ok) 
        {
            cout << x << endl;
            ok = 0;
        }
    }

    if (ok) cout << "sim" << endl;
}