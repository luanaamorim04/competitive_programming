#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, arr[300009], maxn, ans;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = INF;
        maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            maxn = max(maxn, arr[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == maxn)
            {
                if (i > 1 && arr[i - 1] != maxn) 
                {
                    ans = i;
                    break;
                }
                if (i < n && arr[i + 1] != maxn)
                {
                    ans = i;
                    break;
                }
            }
        }

        cout << (ans != INF ? ans : -1) << endl;
    }
}