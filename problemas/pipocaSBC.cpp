#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, c, t, cap[100009];

int p(long long x)
{
    long long tot;
    int idx = 0;
    for (int i = 0; i < c; i++)
    {
        tot = t*x;
        while (tot >= cap[idx] && idx < n)
        {
            tot -= cap[idx];
            idx++;
        }
    }

    return idx == n;
}

int main()
{_  
    cin >> n >> c >> t;
    for (int i = 0; i < n; i++)
        cin >> cap[i];
    
    long long ini = 1, fim = INF, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (p(meio)) fim = meio - 1;
        else ini = meio + 1;
    }

    cout << fim + 1 << endl;
}