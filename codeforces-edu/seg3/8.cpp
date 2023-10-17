//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 10LL)
#define INF (int) (1e9 + 10LL)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
//#define int long long

using namespace std;

struct tree
{
	int soma;	
};

int resp[MAXN], n, m, arr[MAXN], a, b, op;
tree st[MAXN<<2];

tree join(tree esq, tree dir)
{
	tree resp;
	resp.soma = esq.soma+dir.soma;
	return resp;
}

void build(int idx, int i, int j)
{
    if (i == j)
    {
		st[idx].soma = 1;
		return;
    }
    int mid = (i+j)/2;
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
    if (i == j)
    {
		st[idx].soma = val;
		return;
    }
    int mid = (i+j)/2;
    if (pos <= mid)update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int soma)
{
	if (i == j) return i;
    int mid = (i+j)/2;
	if (soma <= st[esq(idx)].soma) return query(esq(idx), i, mid, soma);
	return query(dir(idx), mid+1, j, soma - st[esq(idx)].soma);	
}

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	int tot = n;
	cout << query(1, 1, n, 2) << endl;
	//for (int i = n; i >= 1; i--)
	//{
	//	int pos = query(1, 1, n, tot - arr[i]);
	//	cout << tot - arr[i] << endl;
	//	resp[i] = pos;
	//	update(1, 1, n, pos, -1);
	//	--tot;
	//}	

	for (int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << endl;

}
//1 1 1 1 1
//1 0 1 1 1
//1 0 1 1 0
// 
