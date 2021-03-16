#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, q, psa[1003][1003], a1, a2, b1, b2;
char c;

int main()
{_
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1];
            if (c == '*')
                psa[i][j]++;
        }

    while (q--)
    {
        cin >> a1 >> b1 >> a2 >> b2;
        cout << psa[a2][b2] - psa[a1 - 1][b2] - psa[a2][b1 - 1] + psa[a1 - 1][b1 - 1] << endl;
    }
    
}