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
#define MAXN 1000000000000LL
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long t, n, x, cubes[100001];

int bb(long long x)
{
    int ini = 1, meio, fim = 10000;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (cubes[meio] == x) return 1;
        else if (cubes[meio] > x) fim = meio - 1;
        else ini = meio + 1;
    }
    return 0;
}

void ini()
{
    for (long long i = 1LL; (i*i*i) <= MAXN; i++)
    {
        cubes[(int) i] = i*i*i;
    }
}

int main()
{_
    cin >> t;
    ini();
    while (t--)
    {
        cin >> n;
        int ok = 0;
        for (long long i = 1; i*i*i <= n; i++)
        {
            if (bb(n - (i*i*i)))
            {
                ok = 1;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
}