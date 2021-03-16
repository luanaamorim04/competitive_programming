#include <iostream>

using namespace std;

int main()
{
    int n, c, m;
    cin >> n >> c >> m;
    int stamp[c], fig, res = c;

    for (int i = 0; i < c; i++)
        cin >> stamp[i];

    for (int i = 0; i < m; i++)
    {
        cin >> fig;
        for (int j = 0; j < c; j++)
        {
            if (fig == stamp[j])
            {
                res--;
                stamp[j] = -1;
                break;
            }
        }
    }

    cout << res << endl;
}