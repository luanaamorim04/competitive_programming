#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <set>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int l, c, a[2000009], ans[2], tam, idx, j;
set<int> k;
map<int, int> qnt;

int main()
{_
    cin >> l >> c;
    int n = 2*l*c - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        qnt[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        tam = k.size();
        k.insert(qnt[a[i]]);
        if (tam != k.size())
        {
            ans[idx++] = a[i];
        }
        else
        {
            j = qnt[a[i]];
            if (idx == 2) break;
        }
    }

    if (qnt[ans[0]] == j)
        cout << ans[1] << endl;
    else 
        cout << ans[0] << endl;

}