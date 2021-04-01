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
#define esq(x) (x<<1)
#define dir(x) ((x<<1) | 1)
#define INF (1e9 + 1)
#define MAX (1<<20)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int st[MAX*4], arr[MAX], n, q, x, a, b;

void build(int idx, int i, int j)
{
    if (i == j)
    {
        st[idx] = arr[i];
        return;
    }
    int mid = ((i+j)>>1);
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = min(st[dir(idx)], st[esq(idx)]);
}

int query(int idx, int i, int j, int l, int r)
{
    if (l > j || r < i) return INF;
    if (l <= i && j <= r) return st[idx];
    int mid = ((i+j)>>1);
    int e = query(esq(idx), i, mid, l, r);
    int d = query(dir(idx), mid+1, j, l, r);
    return min(e, d);
}

void update(int idx, int i, int j, int pos, int val)
{
    if (i == j)
    {
        st[idx] = arr[pos] = val;
        return;
    }
    int mid = ((i+j)>>1);
    if (pos <= mid) update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (q--)
    {
        cin >> x >> a >> b;
        if (x == 1)
        {
            update(1, 1, n, a, b);
        }
        else
        {
            cout << query(1, 1, n, a, b) << endl;
        }
    }
}
