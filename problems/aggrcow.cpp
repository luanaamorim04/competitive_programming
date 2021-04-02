#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF (int) (1e9)
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, t, arr[100009];

int f(int x)
{
    int cows = 1, last = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[last] >= x) cows++, last = i;
    }
    return cows >= m;
}

int main()
{_  
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);

        int ini = 0, fim = INF, meio;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (f(meio)) ini = meio + 1;
            else fim = meio - 1;
        }

        cout << ini - 1 << endl;
    }
}