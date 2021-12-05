#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#include <fstream>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ofstream fout ("optmilk.out");
ifstream fin ("optmilk.in");

struct tree
{
	ll maxLR, maxLr, maxlr, maxlR;
};

ll arr[MAX], n, q, a, b, resp;
tree st[MAX<<2];

tree join(tree esq, tree dir)
{
	tree resp;
	resp.maxLR = max(esq.maxLR + dir.maxlR, esq.maxLr + max(dir.maxLR, dir.maxlR));
	resp.maxlr = max(esq.maxlR + dir.maxlr, esq.maxlr + max(dir.maxlr, dir.maxLr));
	resp.maxlR = max(esq.maxlR + dir.maxlR, esq.maxlr + max(dir.maxlR, dir.maxLR));
	resp.maxLr = max(esq.maxLR + dir.maxlr, esq.maxLr + max(dir.maxlr, dir.maxLr));
	return resp;
}	

void build(int idx, int i, int j)
{
	if (i==j)
	{
		st[idx].maxLR = arr[i];
		st[idx].maxLr = 0;
		st[idx].maxlR = 0;
		st[idx].maxlr = 0;
		return;
	}	
	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i==j)
	{
		st[idx].maxLR = val;
		st[idx].maxLr = 0;
		st[idx].maxlR = 0;
		st[idx].maxlr = 0;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	fin >> n >> q;
	for (int i = 1; i <= n; i++)
		fin >> arr[i];

	build(1, 1, n);
	while (q--)
	{
		fin >> a >> b;
		update(1, 1, n, a, b);
		resp += max(max(st[1].maxLR, st[1].maxLr), max(st[1].maxlR, st[1].maxlr));
	}

	fout << resp << endl;
}













