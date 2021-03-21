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

int n, peso, p[2009], v[2009], memo[2009][2009];

int f(int idx, int peso)
{
    if (peso == 0) return 0;
    if (peso < 0 || idx < 1) return -INF;
    if (memo[idx][peso] != -1) return memo[idx][peso];

    return memo[idx][peso] = max(f(idx-1, peso-p[idx]) + v[idx], f(idx-1, peso));
}

int main()
{_
    while (cin >> n >> peso)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i] >> v[i];
            for (int j = 0; j <= peso; j++)
                memo[i][j] = -1;
        }

        cout << f(n, peso) << endl;
    }
}