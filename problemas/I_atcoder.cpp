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

double n, prob[3000], memo[3000][3000];

double f(int idx, int heads)
{
    if (idx == n) return heads > (n - heads);
    if (memo[idx][heads] != -1) return memo[idx][heads];
    return memo[idx][heads] = f(idx + 1, heads + 1)*prob[idx] + f(idx + 1, heads)*(1 - prob[idx]);
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        cin >> prob[i];
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;
    }

    cout << fixed << setprecision(10) << f(0, 0) << endl;
}