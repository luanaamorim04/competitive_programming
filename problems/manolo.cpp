#include <iostream>
#include <vector>

using namespace std;

int fazenda[55][55];
vector< pair<int, int> > V;

bool f(int x, int y)
{
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].first == x && V[i].second == y)
            return false;
    }
    return true;
}

int main()
{
    int n, m, a, b, c, d, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> fazenda[i][j];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        for (int k = a - 1; k < c; k++)
            for (int l = b - 1; l < d; l++)
            {
                if (f(k, l)) res += fazenda[k][l];
                V.push_back(make_pair(k, l));
            }
    }

    cout << res << endl;

    

}