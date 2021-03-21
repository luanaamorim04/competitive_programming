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

int n, p[7], a, b, t;

int main()
{_  
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> a >> b;
            if (a == b) p[a]++;
            else
            {
                p[a]++;
                p[b]++;
            }
        }

        int dif = 0;
        int ok = 1;

        for (int i = 0; i <= 6; i++)
        {
            if (p[i] % 2 == 0) continue;
            dif++;
        }

        if (dif > 2) ok = 0;
        cout << "Teste " << ++t << endl << (ok ? "sim" : "nao") << endl << endl;
    }
}