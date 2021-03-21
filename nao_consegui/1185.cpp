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
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> v[20];
int n, m, x;

int f(int mask, int u)
{
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < v[u].size(); j++)
        {
            f()
        }
    }
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        while (m--)
        {
            cin >> x;
            v[i].push_back(x);
        }
    }

    cout << f(0) << endl;
}