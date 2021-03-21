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

long long n, arr[100009], s, memo[100009];

long long f(int idx)
{
    if (memo[idx] != -1) return memo[idx];
    long long ans = INF;
    for (int i = idx; i < n; i++)
        ans = min(ans, s + f(i + 1) + (arr[i] - arr[idx]));

    return memo[idx] = ans;
}

int main()
{_  
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        memo[i] = -1;
        cin >> arr[i];
    }

    sort(arr, arr+n);

    cout << f(0) << endl;
}