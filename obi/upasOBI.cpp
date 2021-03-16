#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <stack> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, pode[100009];
vector<int> grafo[100009];
stack<int> ans;

int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = n; i >= 1; i--)
    {
        if (!pode[i])
        {
            ans.push(i);
            for (int j = 0; j < grafo[i].size(); j++)
            {
                pode[grafo[i][j]] = 1;
            }
        }
    }

    cout << ans.size() << endl;
    
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}