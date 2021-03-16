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

int main()
{_
    int n, a, b, tot1, tot2, t = 0;
    while (cin >> n && n)
    {
        cout << "Teste " << ++t << endl;
        tot1 = 0; tot2 = 0;
        while (n--)
        {
            cin >> a >> b;
            tot1 += a; tot2 += b;
            cout << tot1 - tot2 << endl;
        }
        cout << endl;
    }
}