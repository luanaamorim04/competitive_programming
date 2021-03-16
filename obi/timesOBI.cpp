#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> time1, time2, grafo[100009];
int n, m, x, timee[100009];
queue<int> fila;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        while (m--)
        {
            cin >> x;
            grafo[i].push_back(x);
            grafo[x].push_back(i);
        }
    }

    timee[1] = 1;
    fila.push(1);
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        (timee[f] == 1 ? time1 : time2).push_back(f);
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!timee[v])
            {
                timee[v] = timee[f]*-1;
                fila.push(v);
            }
        }
    }

    sort(time1.begin(), time1.end());
    sort(time2.begin(), time2.end());

    for (int i = 0; i < time1.size(); i++)
        cout << time1[i] << ' ';

    cout << endl;

    for (int i = 0; i < time2.size(); i++)
        cout << time2[i] << ' ';

    cout << endl;
}