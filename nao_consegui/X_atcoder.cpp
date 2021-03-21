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
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct caixa
{
    int p, w, v;
};

caixa box[100009];

int p[10009], w[100009], v[100009], n;

int f(int idx, int peso)
{
    cout << peso << ' ';
    if (peso < 0) return -INF;
    if (idx == n) return 0;
    return max(f(idx + 1, min(peso - box[idx].p, box[idx].w)) + box[idx].v, f(idx + 1, peso));
}

int cmp(caixa a, caixa b)
{
    return a.w > b.w;
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> box[i].p >> box[i].w >> box[i].v;
    }

    sort(box, box+n, cmp);

    cout << f(0, INF) << endl;
}