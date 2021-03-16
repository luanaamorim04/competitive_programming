#include <iostream>
#include <vector>
#include <queue>
#define mp make_pair
#define par pair<int, int>

using namespace std;

int n, m, a, v[1000], fs, sc;
priority_queue< par, vector<par>, greater<par> > fila;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (i < n)
        {
            fila.push(mp(a, (i + 1)));
            v[i + 1]++;
        }
        else
        {
            fs = fila.top().first;
            sc = fila.top().second;
            v[sc]++;
            fila.pop();
            fila.push(mp(a + fs, sc));
        }
    }

    for (int i = 0; i < n; i++)
        cout << i + 1 << ' ' << v[i + 1] << endl;

    cout << endl;
}