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

int t, n, peso, p, v, pd[1009];

int main()
{_
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> peso;
        for (int k = peso; k >= 0; k--)
            pd[k] = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> v >> p;
            for (int k = peso; k >= p; k--)
                pd[k] = max(pd[k], pd[k - p] + v);
        }

        cout << "Galho " << i << ":\nNumero total de enfeites: " << pd[peso] << endl << endl;
    }
}