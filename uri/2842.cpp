#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <cstring>
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int memo[1001][1001], s1, s2;
string a, b;

int f(int ia, int ib)
{
    if (~memo[ia][ib]) return memo[ia][ib];
    if (ia == a.size() || ib == b.size()) return 0;
    if (a[ia] == b[ib]) return memo[ia][ib] = f(ia + 1, ib + 1) + 1;
    return memo[ia][ib] = max(f(ia + 1, ib), f(ia, ib + 1));
}

int main()
{_
    cin >> a >> b;
    memset(memo, -1, sizeof(memo));
    cout << ((int) a.size() + (int) b.size() - f(0, 0)) << endl;
}