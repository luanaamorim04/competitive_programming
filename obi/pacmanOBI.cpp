#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, ans, atual;
char tab[101][101];

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tab[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i%2)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (tab[i][j] == 'o') atual++;
                else if (tab[i][j] == 'A') atual = 0;
                ans = max(ans, atual);
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (tab[i][j] == 'o') atual++;
                else if (tab[i][j] == 'A') atual = 0;
                ans = max(ans, atual);
            }   
        }
    }
    cout << ans << endl;
}