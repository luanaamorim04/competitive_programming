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

int tab[101][101], n, a, b, d, k, passou[101][101], i;

int main()
{_  
    cin >> n >> k;
    for (i = 1; i <= k; i++)
    {
        cin >> a >> b >> d;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << tab[i][j] << (j == n - 1 ? '\n' : ' ');
}