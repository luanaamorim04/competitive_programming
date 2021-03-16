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

int n, m, k;
par sapo[109];

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> sapo[i].first >> sapo[i].second;

    for (int i = 1; i <= n; i++)
    {
        k = 0;
        for (int j = 0; j < m; j++)
        {
            k += ((i - (sapo[j].first % sapo[j].second)) % sapo[j].second == 0);
        }

        cout << (k ? 1 : 0) << endl;
    }
}