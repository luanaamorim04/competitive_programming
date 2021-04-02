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

int pode[10][10];
string s;
int ok(int a, int b)
{
    return (a >= 0 && b >= 0 && a < 7 && b < 7 && !pode[a][b]);
}



int f(int a, int b, int idx)
{
    if (a == 6 && b == 6) return 1;
    pode[a][b] = 1;
    int resp = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((i && j) || !ok(a + i, b + j)) continue;
            resp += f(a + i, b + j, idx + 1);
        }
    }
    
    return resp;
}

int main()
{_
    //cin >> s;
    cout << f(0, 0, 0) << endl;
}
