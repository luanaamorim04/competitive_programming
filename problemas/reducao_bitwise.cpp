#include <iostream>
#define ll long long
#define INF (ll) ((1LL<<32) - 1)
#define MAX (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define SETADO ((1LL<<32) - 1)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct tree
{
	int maior, menor;
	ll andand, oror, xorxor;
};

char op;
ll arr[MAX + 1], n, m, a, b;
tree st[4*MAX];

tree combine(tree esq, tree dir)
{
	tree resp;
	resp.maior = (arr[esq.maior] > arr[dir.maior] ? esq.maior : dir.maior);
	resp.menor = (arr[esq.menor] < arr[dir.menor] ? esq.menor : dir.menor);
	resp.andand = ((esq.andand)&(dir.andand));
	resp.oror = ((esq.oror)|(dir.oror));
	resp.xorxor = ((esq.xorxor)^(dir.xorxor));
	return resp;
}

void build(int idx, int i, int j)
{	
	if (i == j)
	{
		st[idx] = {i, i, arr[i], arr[i], arr[i]};
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l || l > r) return {0, MAX, SETADO, 0LL, 0LL};

	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return combine(x, y);
}

void update(int idx, int i, int j, int pos)
{
	if (i == j)
	{
		st[idx] = {i, i, arr[i], arr[i], arr[i]};
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos);
	else update(dir(idx), mid+1, j, pos);
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	arr[MAX] = INF, arr[0] = -1;
	build(1, 1, n);

	while (m--)
	{
		cin >> op >> a >> b;
		if (op == 'x')
		{
			tree ans = query(1, 1, n, a, b);
			if (ans.xorxor == 0) cout << arr[ans.maior] << endl;
			else cout << -1 << endl;
		}
		else if (op == 'a')
		{
			tree ans = query(1, 1, n, a, b);
			int mn = ans.menor;
			tree e = query(1, 1, n, a, mn-1);
			tree d = query(1, 1, n, mn+1, b);
			if (arr[ans.menor] == (e.andand&d.andand)) cout << arr[ans.menor] << endl;
			else cout << -1 << endl;
		}
		else if (op == 'o')
		{
			tree ans = query(1, 1, n, a, b);
			int mx = ans.maior;
			tree e = query(1, 1, n, a, mx-1);
			tree d = query(1, 1, n, mx+1, b);
			if (arr[ans.maior] == (e.oror|d.oror)) cout << arr[ans.maior] << endl;
			else cout << -1 << endl;
		}
		else 
		{
			arr[a] = b;
			// for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
			// 	cout << endl;
			update(1, 1, n, a);
		}
	}

	cout << endl;
}
















