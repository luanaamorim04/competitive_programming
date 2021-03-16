#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, choco[100100], ans;

int cmp(int a, int b)
{
    return a > b;
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> choco[i];
        ans += choco[i];
    }

    sort(choco, choco+n, cmp);

    for (int i = 2; i < n; i += 3)
    {
        ans -= choco[i];
    }

    cout << ans << endl;
}