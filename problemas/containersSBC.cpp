#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, vector<int> >
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<vector<int>, int> dist;
vector<int> o(8), dest(8), f, v;
priority_queue<par, vector<par>, greater<par> > pq;

void vertice(vector<int> f);

int main()
{_
    for (int i = 0; i < 8; i++)
        cin >> o[i];
    for (int i = 0; i < 8; i++)
        cin >> dest[i];

    pq.push(make_pair(-1, o));
    dist[o] = -1;
    while (!pq.empty())
    {
        f = pq.top().second; int d = pq.top().first; pq.pop();
        if (d > dist[f]) continue;
        if (f == dest) break;
        vertice(f);
    }

    cout << dist[dest] + 1 << endl;
}

void vertice(vector<int> f)
{
    v = f;
    for (int i = 0; i < 8; i++)
    {
        int k = i < 4 ? i + 4: i - 4;

        swap(v[i], v[k]);
        if (!dist[v]) dist[v] = INF;
        
        if (dist[v] > dist[f] + v[i] + v[k])
        {
            dist[v] = dist[f] + v[i] + v[k];
            pq.push(make_pair(dist[v], v));
        }
        swap(v[i], v[k]);

        if (i > (i < 4 ? 0 : 4)) 
        {
            swap(v[i], v[i - 1]);
            if (!dist[v]) dist[v] = INF;
            
            if (dist[v] > dist[f] + v[i] + v[i - 1])
            {
                dist[v] = dist[f] + v[i] + v[i - 1];
                pq.push(make_pair(dist[v], v));
            }
            swap(v[i], v[i - 1]);
        }

        if (i < (i < 4 ? 3 : 7)) 
        {
            swap(v[i], v[i + 1]);
            if (!dist[v]) dist[v] = INF;
            
            if (dist[v] > dist[f] + v[i] + v[i + 1])
            {
                dist[v] = dist[f] + v[i] + v[i + 1];
                pq.push(make_pair(dist[v], v));
            }
            swap(v[i], v[i + 1]);
        }
    }
}