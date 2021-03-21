#include <iostream>
#define INF (int) 1e9 + 9;
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 100009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int st[1<<20], arr[1<<20], n, q, mid;
 
void construct(int l, int r, int idx)
{
    if (l == r) 
    {
        st[idx] = arr[l];
        return;
    }
    mid = (l + r)>>1;
    construct(l, mid, 2*idx);
    construct(mid + 1, r, 2*idx + 1);
    st[idx] = max(st[2*idx + 1], st[2*idx]);
}
 
int query(int l, int r, int idx, int x, int y)
{
    if (l >= x && r <= y) return st[idx]; // completamente dentro do range
    if (l > y || r < x) return 0; // completamente fora do range
    mid = (l + r)>>1;
    return max(query(l, mid, idx*2, x, y), query(mid + 1, r, idx*2 + 1, x, y));
}
 
void update(int l, int r, int idx, int pos, int val)
{
    if (l > pos || r < pos) return; // pos a alterar completamente fora do range
    if (l == r) 
    {
        st[idx] = val;
        return;
    }
    mid = (l + r)>>1;
    update(l, mid, idx*2, pos, val);
    update(mid + 1, r, idx*2 + 1, pos, val);
    st[idx] = max(st[2*idx + 1], st[2*idx]);
}
 
int main()
{_  
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
 
    construct(1, n, 1);

    while (q--)
    {
        int ini = 1, fim = n, meio, val;
        cin >> val;
        while (ini <= fim)
        {
            meio = ini + (fim - ini)/2;
            if (query(1, n, 1, 1, meio) >= val) fim = meio - 1;
            else ini = meio + 1;
        }
        if (fim == n) 
        {
            cout << 0 << ' ';
            continue;
        }
        cout << fim + 1 << ' ';
        update(1, n, 1, fim + 1, arr[fim + 1] - val);
        arr[fim + 1] -= val;
    }
    cout << endl;
}