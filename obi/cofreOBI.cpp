#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int v[100001][10], n, m, a, last, ans[10];

int main()
{_
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 0; j < 10; j++)
            v[i][j] = v[i - 1][j];

        ++v[i][a];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        if (last < a)
            for (int j = 0; j < 10; j++)
                ans[j] += v[a][j] - v[last][j];
        else
            for (int j = 0; j < 10; j++)
                ans[j] += v[last - 1][j] - v[a - 1][j];
        last = a;
    }

    for (int j = 0; j < 10; j++)
        cout << ans[j] << ' ';
}