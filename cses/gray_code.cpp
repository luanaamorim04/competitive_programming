#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, k;
map<string, int> passou;
int n;

void dfs(string s)
{
    passou[s] = 1;
    cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        s[i] == '1' ? s[i] = '0' : s[i] = '1';
        if (!passou.count(s)) dfs(s);
        s[i] == '1' ? s[i] = '0' : s[i] = '1';
    }
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
        s += '0';
    dfs(s);
}