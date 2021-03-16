
#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 2000009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, arr[MAXN], ans, ini, fim, K, soma;

int main()
{_
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    ini = 1, fim = 1;
    soma = arr[1];

    while (ini <= n)
    {
        if (fim - ini >= n) 
        {
            soma -= arr[ini];
            ini++;
        }
        else if (soma == K) 
        {
            soma -= arr[ini];
            ans++;
            ini++;
            fim++;
            soma += arr[fim];
        }
        else if (soma < K) 
        {
            fim++;
            soma += arr[fim];
        }
        else if (soma > K) 
        {
            soma -= arr[ini];
            ini++;
        }
    }

    cout << ans << endl;
}