#include <iostream>
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long
#define _ ios_base::sync_with_stdio(false); cin->tie(0);

using namespace std;

struct tree
{
	int maior, menor, smenor, smaior;
};

void push(int idx, int i, int j)
{

}

void atmost(int idx, int i, int j, int l, int r, int h)
{
	if (i > r || j < l || st[idx].maior <= h) return;
	if (i >= l && j <= r && st[idx].smaior < h)
	{
		lazy[idx].maior = h;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	atmost(esq(idx), i, mid, l, r, h);
	atmost(dir(idx), mid+1, j, l, r, h);
}


int32_t main()
{
	cin >> n >> q;
	while (q--)
	{
		cin >> op >> l >> r >> h;
		update(1, 0, n-1, l, r, h);
	
	}
}
