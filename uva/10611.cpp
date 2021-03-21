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

long long n, q, arr[50001], x;

int maxmin(int x)
{
    int ini = 1, fim = n, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (x > arr[meio]) ini = meio + 1;
        else fim = meio - 1;
    }
    
    return (ini - 1 >= 1 ? arr[ini - 1]: -1);
}

int minmax(int x)
{
    int ini = 1, fim = n, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (x < arr[meio]) fim = meio - 1;
        else ini = meio + 1;
    }

    return (fim + 1 <= n ? arr[fim + 1]: -1);
}

int main()
{_  
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        int a = maxmin(x);
        int b = minmax(x);
        if (a != -1) cout << a << ' ';
        else cout << "X ";
        if (b != -1) cout << b << endl;
        else cout << "X\n";
    }
}