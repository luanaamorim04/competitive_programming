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
#define MAXN (int) 1e6
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, ans;

long long d(long long a, long long b)
{
    return (a*b) + ((a - 1) * (b - 1));
}

int main()
{_  
    cin >> n;
    for (int i = 2; i <= MAXN; i++)
    {
        long long ini = 2, fim = n - 1, meio;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (d(meio, i) == n && meio >= i)
            {
                ans++;
                break;
            }
            else if (d(meio, i) > n)
            {
                fim = meio - 1;
            }
            else
            {
                ini = meio + 1;
            }
        }
    }

    cout << ans << endl;
}