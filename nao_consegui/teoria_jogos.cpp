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

int n, m, pos[1000009];

void f(int n)
{
    if (n < 0) return;
    if (!n) pos[n] = 1;
    int ans = 1;
    for (int i = m; i >= n; i--)
        pos[n] = -1 * pos[n - i];
}

int main()
{_  
    cin >> n >> m;
    pos[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i >= j) pos[i] = -pos[i - j];
        }
    }

    cout << (pos[n] == -1 ? "Paula" : "Carlos") << endl;
}