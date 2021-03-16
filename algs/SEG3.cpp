#include <iostream>
#define INF (int) 1e9 + 9;
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 100009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int st[800009], arr[400009], n, q, a, b, x;

void construct(int l, int r, int idx)
{
    if (l == r) 
    {
        st[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    construct(l, mid, 2*idx);
    construct(mid + 1, r, 2*idx + 1);
    st[idx] = min(st[2*idx + 1], st[2*idx]);
}

int query(int l, int r, int idx, int x, int y)
{
    if (l >= x && r <= y) return st[idx];
    if (l > y || r < x) return INF;
    int mid = (l + r) / 2;
    return min(query(l, mid, idx*2, x, y), query(mid + 1, r, idx*2 + 1, x, y));
}

void update(int l, int r, int idx, int x, int val)
{
    if (l > x || r < x) return;
    if (l == r) 
    {
        st[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, idx*2, x, val);
    update(mid + 1, r, idx*2 + 1, x, val);
    st[idx] = min(st[2*idx + 1], st[2*idx]);
}

int main()
{_  
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    construct(1, n, 1);

    while (q--)
    {
        cin >> x >> a >> b;
        if (x == 2) cout << query(1, n, 1, a, b) << endl;
        else update(1, n, 1, a, b);
    }
}