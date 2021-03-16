#include <iostream>

using namespace std;

int n, f;
char m[500][500];

void fissura(int i, int j);

int main()
{
    cin >> n >> f;
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
        {
            cin >> m[k][l];
        }

    if (m[0][0] - '0' <= f)
    {
        fissura(0, 0);
        m[0][0] = '*';
    }

    cout << endl;

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            cout << m[k][l];
        }
        cout << endl;
    }
}

void fissura(int i, int j)
{
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1) return;

    if (m[i + 1][j] != '*' && m[i + 1][j] - '0' <= f && (i + 1) <= n - 1)
    {
        m[i + 1][j] = '*';
        fissura(i + 1, j);
    }
    if (m[i - 1][j] != '*' && m[i - 1][j] - '0' <= f && (i - 1) >= 0)
    {
        m[i - 1][j] = '*';
        fissura(i - 1, j);
    }
    if (m[i][j + 1] != '*' && m[i][j + 1] - '0' <= f && (j + 1) <= n - 1)
    {
        m[i][j + 1] = '*';
        fissura(i, j + 1);
    }
    if (m[i][j - 1] != '*' && m[i][j - 1] - '0' <= f && (j - 1) >= 0)
    {
        m[i][j - 1] = '*';
        fissura(i, j - 1);
    }

    return;
}