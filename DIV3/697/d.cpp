#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, t, m, b[2][200001], arr[200001], x, id[2];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) 
        {
            cin >> x;
            b[x - 1][++id[x - 1]] = arr[i];
        }

        sort(b[0], b[0]+idx[0], greater<int>());
        sort(b[1], b[1]+idx[1], greater<int>());

        for (int i = 0; i < idx[1]; i++)
        {
            if (m <= 0) break;
            m -= b[1][i];
        }
    }
}