#include <iostream>

using namespace std;

int m[1001][1001], x, y, l, c;
void track(int a, int b)
{
    if (!m[a][b]) return;
    m[a][b] = 0;
    x = a; y = b;
    track(a + 1, b);
    track(a - 1, b);
    track(a, b + 1);
    track(a, b - 1);
}

int main()
{
    cin >> l >> c >> x >> y;

    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= c; j++)
            cin >> m[i][j];

    track(x, y);

    cout << x << ' ' << y << endl;

}