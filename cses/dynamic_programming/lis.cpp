#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, arr[200009], ft[200009], copia[200009], ans;
map<int, int> mapa;

int query(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans = max(ans, ft[idx]);
        idx -= ((idx) & (-idx));
    }
    return ans;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] = max(ft[idx], val);
        idx += ((idx) & (-idx));
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        copia[i - 1] = arr[i];
    }

    sort(copia, copia+n);

    for (int i = 1; i <= n; i++)
        mapa[copia[i - 1]] = i;

    for (int i = 1; i <= n; i++)
    {
        update(mapa[arr[i]] + 1, query(mapa[arr[i]]) + 1);
        ans = max(ans, query(mapa[arr[i]]) + 1);
    }

    cout << ans << endl;
}