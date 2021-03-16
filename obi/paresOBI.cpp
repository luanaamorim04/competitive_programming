#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <stack> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, v[1009], ans;

int main()
{_
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] >= a && v[i] + v[j] <= b) ans++;
        }
    }

    cout << ans << endl;
}   