#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/*
    given a graph and a node e, how many nodes can e reach?
*/

int n; //the number of nodes in the graph
int m; //the number of edges in the graph
int seen[1009], a, b, ans, e;
queue<int> line;
vector<int> graph[1009];

int main()
{_
    cin >> n >> m;
    while (m--) // get all conections
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> e;  // get the node

    line.push(e);
    seen[e] = 1;
    while (!line.empty()) // do bfs in the conected componente of e
    {
        int f = line.front(); line.pop(); // pop from queue
        ans++;
        for (int j = 0; j < graph[f].size(); j++)
        {
            if (seen[graph[f][j]]) // only pass trough unvisited nodes
            {
                seen[graph[f][j]] = 1; // mark as passed
                line.push(graph[f][j]); // "now" i'm gonn visite this node
            }
        }
    }

    cout << ans << endl;
}