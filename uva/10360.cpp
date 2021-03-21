#include <iostream>
#include <cstring>

using namespace std;

int d, n, D, t, x, y, z, psa[1100][1100], resp;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> D >> n;
        d = D*2 + 1;
        resp = 0;
        while (n--)
        {
            cin >> x >> y >> z;
            psa[x][y] = z;
        }

        for (int i = 1; i < 1100; i++)
            for (int j = 1; j < 1100; j++)
                psa[i][j] += psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1];

        for (int i = 1; i < 1100; i++)
        {
            for (int j = 1; j < 1100; j++)
            {
                int ix = max(0, i - d);
                int jx = max(0, j - d);
                if (resp < psa[i][j] - psa[i][jx] - psa[ix][j] + psa[ix][jx])
                {
                    resp = psa[i][j] - psa[i][jx] - psa[ix][j] + psa[ix][jx];
                    x = i, y = j;
                }
            }
        }

        cout << x - D << ' ' << y - D << ' ' << resp << endl;
        memset(psa, 0, sizeof(psa));
    }
}