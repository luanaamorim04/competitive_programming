#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<long long, long long>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long t, n, m, x, y, pai[1000];
par v[1000];
vector<pair<long long, par> > arestas;

long long dist(par a, par b)
{
    long long x = a.first - b.first;
    long long y = a.second - b.second;
    return (x*x) + (y*y);
}

long long find(long long x)
{
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join(long long a, long long b)
{
    a = find(a), b = find(b);
    pai[a] = b;
}

int main()
{_  
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (long long i = 1; i <= n; i++)
        {
            pai[i] = i;
            cin >> x >> y;
            v[i] = par(x, y);
            for (long long j = 1; j < i; j++)
            {
                arestas.push_back(make_pair(dist(v[i], v[j]), par(i, j)));
                arestas.push_back(make_pair(dist(v[i], v[j]), par(j, i)));
            }
        }

        sort(arestas.begin(), arestas.end());

        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            join(x, y);
        }

        for (int i = 0; i < arestas.size(); i++)
        {
            long long a = arestas[i].second.first, b = arestas[i].second.second;
            if (find(a) == find(b)) continue;
            cout << a << ' ' << b << endl;
            join(a, b);
        }

        arestas.clear();
    }
}

