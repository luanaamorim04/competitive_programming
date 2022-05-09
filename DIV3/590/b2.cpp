#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 100009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[201], sum, k;
queue<int> fila;
vector<int> v;
map<int, int> mapa;

int main()
{_  
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mapa[x]) continue;
        if (fila.size() < k) 
        {
            fila.push(x);
            mapa[x]++;
        }
        else
        {
            fila.push(x);
            mapa[x]++;
            mapa[fila.front()]--;
            fila.pop();
        }
    }

    cout << fila.size() << endl;
    while (!fila.empty())
    {
        v.push_back(fila.front());
        fila.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << ' ';
}