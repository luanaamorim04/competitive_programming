#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, c, k, ans, primos[41];

long long f(int idx, int cj, long long num)
{
    long long ans = 0;
    for (int i = idx + 1; i <= c; i++)
    {
        if (cj) ans -= (n/(num*primos[i]));
        else ans += (n/(num*primos[i]));
        if (num*primos[i] < n) ans += f(i, cj^1, num*primos[i]);
    }

    return ans;
}

int main()
{_  
    cin >> n >> c;
    for (int i = 1; i <= c; i++)
        cin >> primos[i];

    cout << n - f(0, 0, 1) << endl;
}