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

int n, m, arr[1009], ans, k;

int desn(int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1]) ans += (arr[i] - arr[i - 1]);

    int resp = 0;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1]) resp += (arr[i] - arr[i + 1]);

    return min(resp, ans);
}

int main()
{_  
    cin >> n;
    k = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
            cin >> arr[j];

        if (k > desn(m))
        {
            k = desn(m);
            ans = i + 1;
        }
    }

    cout << ans << endl;
}