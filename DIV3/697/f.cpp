#include <iostream>
#include <set>

using namespace std;

char c;
int t, n, matriz[1001][1001], x;
set<int> cj[2];

int main()
{
    cin >> t;
    while (t--)
    {
        int pode = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                matriz[i][j] = c - '0';
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                matriz[i][j] ^= (c - '0');
            }

        cj[0].insert(0);
        for (int i = 0; i < n; i++)
        {
            if (matriz[0][i]) cj[1].insert(i + n);
            else cj[0].insert(i + n);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int col = (cj[0].count(j + n));
                if (matriz[i][j])
                {   
                    if (cj[col].count(i)) pode = 0;
                    cj[col^1].insert(i); 
                }
                else
                {
                    if (cj[col^1].count(i)) pode = 0;
                    cj[col].insert(i); 
                }
            }
        }

        cj[0].clear(), cj[1].clear();

        cout << (pode ? "YES" : "NO") << endl;
    }
}