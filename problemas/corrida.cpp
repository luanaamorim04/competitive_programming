#include <iostream>
#include <algorithm>
#include <vector>
#define vii vector< pair<int, int> >
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define line '\n'

using namespace std;

int m, n, p;

int main()
{
    cin >> n >> m;
    vii v;
    for (int i = 0; i < n; i++)
    {
        p = 0;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            p += a;
        }
        v.pb(mp(p, i + 1));
    }

    sort(all(v));
    for (int i = 0; i < 3; i++)
        cout << v[i].second << endl;
}