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

int n, m, t, arr[109], pos[109], x, k, j;

int main()
{_  
    while (cin >> n >> m && n)
    {
        cout << "Teste " << ++t;
        for (int i = 0; i < n; i++)
            cin >> pos[i];

        int ok = 0;
        while (m--)
        {
            cin >> x;
            j = 0;
            for (int i = 0; i < x; i++)
            {
                cin >> k;
                j += k;
            }
            ok = 1;
        }
    }
}