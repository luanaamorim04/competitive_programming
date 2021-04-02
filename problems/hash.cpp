#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int main()
{
    int t, m, n, num;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        vector<int> res[m];
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            res[num % m].pb(num);
        }

        for (int i = 0; i < m; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " -> ";
            }
            cout << "\\" << endl;
        }

        if (t > 0) cout << endl;
    }
}