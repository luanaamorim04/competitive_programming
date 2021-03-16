#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, int> mapa;
int n, arr[100009], copia[100009], ft[100009], ans;

int query(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans = max(ft[idx], ans);
        idx -= lsb(idx);
    }
    return ans;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] = max(ft[idx], val);
        idx += lsb(idx);
    }
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> copia[i];
        arr[i + 1] = copia[i];
    }

    sort(copia, copia+n);

    for (int i = 0; i < n; i++)
        mapa[copia[i]] = i + 1;

    for (int i = 1; i <= n; i++)
        update(mapa[arr[i]], query(mapa[arr[i]]) + 1);

    cout << query(n) << endl;
}