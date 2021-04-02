#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo['z' + 1], resp;
int n, passou['z' + 1], ok, grau['z' + 1], ar['z' + 1]['z' + 1];
string s;

void dfs(int u, int p)
{
    resp.push_back(u);
    passou[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (v == p) continue;
        if (passou[v]) ok = 0;
        else dfs(v, u);
    }
}

int main()
{_
    cin >> n;
    while (n--)
    {
        ok = 0;
        cin >> s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (ar[s[i]][s[i + 1]]) continue;
            ar[s[i]][s[i + 1]] = ar[s[i + 1]][s[i]] = 1;
            grafo[s[i]].push_back(s[i + 1]);
            grafo[s[i + 1]].push_back(s[i]);
            grau[s[i]]++, grau[s[i + 1]]++;
            if (grau[s[i]] > 2 || grau[s[i + 1]] > 2) ok = 0;
        }

        for (int i = 'a'; i <= 'z'; i++)
        {
            if (grau[i] == 1) 
            {
                ok = 1;
                dfs(i, -1); break;   
            }
        }

        if (s.size() == 1) ok = 1;

        if (!ok) cout << "NO" << endl;
        else
        {   
            cout << "YES" << endl;
            for (int i = 0; i < resp.size(); i++)
                cout << (char) resp[i];
            for (char i = 'a'; i <= 'z'; i++)
            {
                grafo[i].clear();
                if (!passou[i]) cout << (char) i;
            }
            cout << endl;   
        }
        resp.clear();
        memset(ar, 0, sizeof(ar));
        memset(passou, 0, sizeof(passou));
        memset(grau, 0, sizeof(grau));
    }
}
