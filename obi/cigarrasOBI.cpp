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

long long n, k, mmc, mdc, ans, maxn, x, a;

int f(int a, int b)
{
    if (!b) return a;
    return f(b, a%b);
}

int main()
{_
    cin >> n >> k;
    cin >> ans;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        mdc = f(a, ans);
        ans = mdc * (a / mdc) * (ans / mdc);
    }

    for (int i = 1; i <= k; i++)
    {
        mdc = f(i, ans);
        mmc = mdc * (i / mdc) * (ans / mdc);
        if (mmc > maxn && mmc <= k)
        {
            maxn = mmc;
            x = i;
        }
    }

    cout << x << endl;
}