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

int t, n, a, b, x, y;

int main()
{_  
    while (cin >> n && n)
    {
        a = 0, b = 0;
        while (n--)
        {
            cin >> x >> y;
            a += x, b += y;
        }

        cout << "Teste " << ++t << endl;
        cout << (a > b ? "Aldo" : "Beto") << endl << endl;
    }
}