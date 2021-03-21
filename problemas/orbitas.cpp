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
#define par pair<long long, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long mdc(long long a, long long b)
{
    if (!b) return a;
    return mdc(b, a % b);
}

int main()
{_  
    long long a, b, ans;
    cin >> a >> b;
    ans = mdc(a, b);
    cout << (a / ans) * b << endl;
}