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

char tab[1001][1001];
int n;

int main()
{_  
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int k = 0, ok = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == '*') k = 1;
            if (tab[i][j] == '.' && k) ok = 1;
            if (tab[i][j] == '*' && ok)  ans = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int k = 0, ok = 0;
        for (int j = 0; j < n; j++)
        {
            if (tab[j][i] == '*') k = 1;
            if (tab[j][i] == '.' && k) ok = 1;
            if (tab[j][i] == '*' && ok)  ans = 0;
        }
    }

    cout << (ans ? 'S' : 'N') << endl;
}