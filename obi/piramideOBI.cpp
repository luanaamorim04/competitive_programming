#include <iostream>

using namespace std;

int n, tab[109][109], memo[109][109], psa[109][109];

int f(int a, int b)
{
    if (a == 1) return tab[a][b];
    if (b + a - 1 > n) return 99999;
    if (memo[a][b] != -1) return memo[a][b];
    return memo[a][b] = psa[a][b + a - 1] - psa[a][b - 1] + min(f(a - 1, b), f(a - 1, b + 1));
}

int main()
{
    cin >> n;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            cin >> tab[a][b];
            psa[a][b] = psa[a][b - 1] + tab[a][b];
            memo[a][b] = -1; 
        }
    }

    cout << f(n, 1) << endl;
}