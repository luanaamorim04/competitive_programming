#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

char x;
int y, s1, s2, nivel[101][101];

int dfs(int a, int b)
{
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (a + i > 0 && b + j > 0 && a + i <= 8 && b + j <= 8 && !nivel[])
            {
                nivel[a + i][]
            }
        }
}

int main()
{_
    cin >> x >> y;
    s1 = 8 - y, s1 = x - 'a';
    cin >> x >> y;
    dfs(8 - y, x - 'a');
    cout << nivel[s1][s2] << endl;
}
