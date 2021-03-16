#include <iostream>
#include <vector>
#include <queue>
#define mp make_pair
#define par pair<int, int>

using namespace std;

int n, a, t, c, ans, f;
priority_queue< int, vector<int>, greater<int> > fila;

int main()
{
    cin >> c >> n;
    for (int i = 0; i < c; i++)
        fila.push(0);

    for (int i = 0; i < n; i++)
    {
        cin >> t >> a;
        f = fila.top();
        fila.pop();
        if (f - t > 20) ans++;
        fila.push(max(f, t) + a);
    }

    cout << ans << endl;
}