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

int n, a[101], A, B, t, memo[5100][101], k;

int f(int soma, int idx)
{
    if (soma == k/2) return 1;
    if (soma > k/2 || idx > n) return 0;
    if (memo[soma][idx] != -1) return memo[soma][idx];
    return memo[soma][idx] = f(soma + a[idx], idx + 1) | f(soma, idx + 1);
}

int main()
{_  
    while (cin >> A >> B >> n && n)
    {
        k = A + B;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            k += a[i];
            for (int j = 0; j < 5100; j++)
                memo[j][i] = -1;
        }

        cout << "Teste " << ++t << endl;
        if (!(k % 2) && f(A, 1)) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}