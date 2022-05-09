#include <iostream>
#include <set>

using namespace std;

set<int> v[200009];
int n, k, arr[200009], counter, pos, resto[200009], ans;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[arr[i] % k].insert(i);
        resto[i] = arr[i] % k;
    }

    while (counter < k)
    {
        if (v[pos].size() >= (n / k))
        {
            int x = v[pos].size() - (n/k);
            ans += x;
            
            while (x--)
            {
                int r = *v[pos].begin();
                v[(pos + 1) % k].insert(r);
                resto[r] = (pos + 1) % k;
                v[pos].erase(v[pos].begin());
            }
            
            counter++;
        }
        pos = (pos + 1) % k;
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] + abs(resto[i] - (arr[i] % k)) << ' ';
    }
    cout << endl;
}