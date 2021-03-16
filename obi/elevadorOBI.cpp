#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, v[10009];

int main()
{_
    cin >> n;
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    sort(v, v+n+1);

    for (int i = 1; i <= n; i++)
    {
        if (v[i] - v[i - 1] > 8)
        {
            cout << 'N';
            return 0;
        }
    }

    cout << 'S';
}