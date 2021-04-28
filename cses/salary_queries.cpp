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
#include <stdio.h>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (1e6)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int n, q, a, b, arr[MAX], ft[MAX], i, v[1<<20], id;
char c;
pair<char, par> qry[MAX];
map<int, int> val;
 
int query(int idx)
{
	int ans = 0;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}
 
void update(int idx, int val)
{
	while (idx < MAX)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}
 
int main()
{_
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		v[++id] = arr[i];
	}
 
	for (i = 1; i <= q; i++)
	{
		scanf("%s %d %d", &(qry[i].first), &(qry[i].second.first), &(qry[i].second.second));
		v[++id] = qry[i].second.first;
		v[++id] = qry[i].second.second;
	}
 
	sort(v+1, v+id+1);
 
	for (i = 1; i <= id; i++)
		val[v[i]] = i;
 
	for (i = 1; i <= n; i++)
	{
		arr[i] = val[arr[i]];
		update(arr[i], 1);
	}
 
	for (i = 1; i <= q; i++)
	{
		a = qry[i].second.first, b = val[qry[i].second.second];
		if (qry[i].first == '!')
		{
			update(arr[a], -1);
			update(b, 1);
			arr[a] = b;
		}
		else
		{
			printf("%d\n", query(b) - query(val[a] - 1));
		}
	}
}