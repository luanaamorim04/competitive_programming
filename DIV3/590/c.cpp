#include <iostream>

using namespace std;

int n, t;
string a[2];

int f(int x, int y, char last)
{
    if (y == n - 1) return x;
    else if (a[x][y] <= '2' && a[x][y + 1] <= '2') return f(x, y + 1, a[x][y]);
    else if (a[x][y] <= '2' && a[x][y + 1] > '2') return f(x^1, y + 1, a[x][y]);
    else if (a[x][y] > '2' && last > '2') return f(x, y + 1, a[x][y]);
    else if (a[x][y] > '2' && last <= '2' && a[x^1][y] > '2') return f(x^1, y + 1, a[x][y]);
    return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> a[0] >> a[1];
        int x = 0, ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[x][i] <= '2') continue;
            else if (a[x][i] > '2' && a[x^1][i] > '2') x^= 1;
            else ans = 0;
        }
        cout << (ans && x ? "YES" : "NO") << endl;
    }
}