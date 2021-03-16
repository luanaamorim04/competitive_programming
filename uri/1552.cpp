#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int a, b;
    double w;
};

int t, n, x, y, pai[505000], tam[505000];
double ans;
par coord[505000];
vector<aresta> grafo;

int cmp(aresta A, aresta B);
double p(par a, par b);
int id(int x);
void join(int a, int b);

int main()
{_
    cin >> t;
    cout << fixed << setprecision(2);
    while (t--)
    {
        cin >> n;
        ans = 0;
        grafo.clear();
    
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            tam[i] = 1;
            pai[i] = i;
            coord[i] = make_pair(x, y);
            for (int j = 1; j < i; j++)
            {
                aresta x;
                x.a = i;
                x.b = j;
                x.w = p(coord[i], coord[j]);
                grafo.push_back(x);
            }
        }

        sort(grafo.begin(), grafo.end(), cmp);

        for (int i = 0; i < grafo.size(); i++)
        {
            int A = id(grafo[i].a), B = id(grafo[i].b);
            if (A == B) continue;
            join(A, B);
            ans += grafo[i].w;
        }

        ans /= 100;

        cout << ans << endl;
    }
}

int cmp(aresta A, aresta B)
{
    return A.w < B.w;
}

double p(par a, par b)
{
    long long x = (b.first - a.first)*(b.first - a.first);
    long long y = (b.second - a.second)*(b.second - a.second);
    return sqrt(x + y);
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}