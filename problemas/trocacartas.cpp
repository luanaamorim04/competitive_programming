#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> a;
set<int> b;
set<int> total;

int main()
{
    int n, m, tmp, res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.insert(tmp);
        total.insert(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        b.insert(tmp);
        total.insert(tmp);
    }

    int x = (int) a.size();
    int y = (int) b.size();

    res = min(x, y) - (x + y - total.size());

    cout << res << endl;
}