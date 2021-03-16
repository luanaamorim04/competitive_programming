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

int n, freq[101], x, ans, maxn;

int main()
{_  
    cin >> n;
    while (n--)
    {
        cin >> x;
        ++freq[x];
        if (freq[x] == maxn)
        {
            ans = max(ans, x);
        }
        else if (freq[x] > maxn)
        {
            maxn = freq[x];
            ans = x;
        }
    }

    cout << ans;
}