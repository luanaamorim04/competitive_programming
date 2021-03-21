#include <iostream>
#include <vector>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, F, R, a, b, v, grafo[101][101], passou[101];
map<pair<int, int>, int >val;

int check(int a, int b)
{
    if (grafo[a][b]) return 1;
    if (passou[a]) return 0;
    passou[a] = 1;

    for (int j = 1; j <= N; j++)
    {
        if (grafo[a][j]) check(j, b);
    }

    return 0;
}

int main()
{_
    cin >> N >> F >> R;
    for (int i = 0; i < F; i++)
    {
        cin >> a >> b >> v;
        if (grafo[a][b] && grafo[a][b] < v) continue;
        grafo[a][b] = v;
        grafo[b][a] = v;
        val[make_pair(a, b)] = v;
    }

    for (int i = 0; i < R; i++)
    {
        cin >> a >> b >> v;
        if (grafo[a][b]) continue;
        grafo[a][b]++;
        grafo[b][a]++;
        val[make_pair(a, b)] = v;
    }

    int x, y;
    cin >> x >> y;
    cout << check(x, y) << endl;
}