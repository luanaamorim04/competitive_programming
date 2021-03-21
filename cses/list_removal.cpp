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

ll ft[1<<20], arr[1<<20], n, x;

ll query(int idx)
{
    ll ans = 0;
    while (idx > 0)
    {
        ans += ft[idx];
        idx -= lsb(idx);
    }
    return ans;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] += val;
        idx += lsb(idx);
    }
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];  
        update(i, 1); 
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        int ini = 1, fim = n, meio;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (query(meio) >= x) fim = meio - 1;
            else ini = meio + 1;
        }
        cout << arr[fim + 1] << ' ';
        update(fim + 1, -1);
    }
    cout << endl;
}
