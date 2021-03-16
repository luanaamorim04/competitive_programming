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

int N, memo[300009][109];
string s;

int f(int n, int last)
{
    if (n == N) return 0;
    if (memo[n][last] != -1) return memo[n][last];
    int x = -INF;
    if (last <= s[n])
    {
        x = 1 + f(n + 1, s[n]);
    }
    return memo[n][last] = max(x, f(n + 1, last));
}

int main()
{_
    cin >> s;
    s.push_back('Z');
    N = s.size();
    for (int i = 0; i <= N; i++)
    {
        for (int j = 'A'; j <= 'Z'; j++)
            memo[i][j] = -1;
    }

    cout << f(0, 'A') - 1 << endl;
}