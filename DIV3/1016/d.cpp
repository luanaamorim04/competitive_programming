#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int a, b, t, n, q;
char op;

ii num(int val, int l, int r, ii tl, ii br)
{
	if (tl == br) return tl;

	if (val <= l + (r-l+1)/4 - 1)
	{
		return num(val, l, l+(r-l+1)/4, tl, {(tl.first+br.first)/2, (tl.second+br.second)/2});
	}
	else if (val <= l + 2*(r-l+1)/4 - 1)
	{
		return num(val, l+(r-l+1)/4, l+2*(r-l+1)/4, {1+(tl.first+br.first)/2, 1+(tl.second+br.second)/2}, br);
	}
	else if (val <= l + 3*(r-l+1)/4 - 1)
	{
		return num(val, l+2*(r-l+1)/4, l+3*(r-l+1)/4, {1+(tl.first+br.first)/2, tl.second}, {br.first, (tl.second+br.second)/2});
	}
	
	return num(val, l+3*(r-l+1)/4, r, {tl.first, 1+(tl.second+br.second)/2}, {(tl.first+br.first)/2, br.second});
}

int pos(ii cord, int l, int r, ii tl, ii br)
{
	if (tl == br) return l;

	if (cord.first <= (tl.first+br.first)/2 && cord.second <= (tl.second+br.second)/2) 
		return pos(cord, l, l+(r-l+1)/4, tl, {(tl.first+br.first)/2, (tl.second+br.second)/2});
	else if (cord.first <= (tl.first+br.first)/2 && cord.second > (tl.second+br.second)/2) 
		return pos(cord, l+3*(r-l+1)/4, r, {tl.first, 1+(tl.second+br.second)/2}, {(tl.first+br.first)/2, br.second});
	else if (cord.first > (tl.first+br.first)/2 && cord.second <= (tl.second+br.second)/2) 
		return pos(cord, l+2*(r-l+1)/4, l+3*(r-l+1)/4, {1+(tl.first+br.first)/2, tl.second}, {br.first, (tl.second+br.second)/2});
	return pos(cord, l+(r-l+1)/4, l+2*(r-l+1)/4, {1+(tl.first+br.first)/2, 1+(tl.second+br.second)/2}, br);
}

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> q;
		n<<=1;
		while (q--)
		{
			cin >> op >> op;
			if (op == '>')
			{
				cin >> a >> b;
				cout << pos({a, b}, 1, 1LL<<n, {1, 1}, {1LL<<(n/2), 1LL<<(n/2)}) << endl;
			}
			else
			{
				cin >> a;
				ii resp = num(a, 1, 1LL<<n, {1, 1}, {1LL<<(n/2), 1LL<<(n/2)});
				cout << resp.first << ' ' << resp.second << endl;
			}
		}
	}
}
