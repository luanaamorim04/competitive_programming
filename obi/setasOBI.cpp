#include <iostream>
#include <vector>

using namespace std;

char tab[505][505];
int n, res = 0;

void check(int x, int y)
{
    if (x < 0 || y < 0 || x > n - 1 || y > n - 1) return;
    res++;
    if (tab[x][y - 1] == '>') check(x, y - 1);
    if (tab[x][y + 1] == '<') check(x, y + 1);
    if (tab[x + 1][y] == 'A') check(x + 1, y);
    if (tab[x - 1][y] == 'V') check(x - 1, y);
    return;
}

int main()
{
    cin >> n;
    vector<int>a;
    vector<int>b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tab[i][j];
            if (j == n - 1 && tab[i][j] == '>')
            {
                a.push_back(i);
                b.push_back(j);
            }
            else if (j == 0 && tab[i][j] == '<')
            {
                a.push_back(i);
                b.push_back(j);
            }
            else if (i == 0 && tab[i][j] == 'A')
            {
                a.push_back(i);
                b.push_back(j);
            }
            else if (i == n - 1 && tab[i][j] == 'V')
            {
                a.push_back(i);
                b.push_back(j);
            }
        }
    }

    for (int i = 0; i < a.size(); i++)
        check(a[i], b[i]);

    cout << (n * n) - res << endl;
}