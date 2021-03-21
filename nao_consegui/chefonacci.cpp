#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 42
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<ll> s;
set<ll>::iterator it;
int n, x, k, fib[45], m;

void back2(ll soma, int idx)
{
    if (idx == k-n) return (void) s.insert(soma);
    for (int i = MAX/2; i <= MAX; i++)
    {
        if (soma + fib[i] <= x) back2(soma + fib[i], idx + 1);
    }
}

void back(int soma, int idx)
{
    if (idx == n) return (void) s.insert(soma);
    for (int i = 1; i < MAX/2; i++)
    {
        if (soma + fib[i] <= x) back(soma + fib[i], idx + 1);
    }
}

int main()
{_
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= MAX; i++)
        fib[i] = (fib[i - 1]+fib[i - 2]);

    // cin >> m;
    // while (m--)
    // {
    //     cin >> x >> k;
    //     n = k/2;
    // }
    cin >> x >> k;
    n = k>>1;
    back(0, 0), back2(0, 0);
    for (it = s.begin(); it != s.end(); it++)
        cout << (*it) << ' ';
    cout << endl;

    // for (int i = 0; i < s2.size(); i++)
    //     cout << s2[i] << ' ';
    // cout << endl;
}