#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define MAX 1<<20
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, ft1[MAX], ft2[MAX], k, ans, y[MAX], contido[MAX], contem[MAX], i, id[MAX], a, b;
par points[MAX];
map<par, int> idx;
map<int, int> val;
set<int> v;

int query1(int idx)
{
	ans = 0;
	while (idx > 0)
	{
		ans += ft1[idx];
		idx -= lsb(idx);
	}
	return ans;
}

void update1(int idx, int val)
{
	while (idx <= k)
	{
		ft1[idx] += val;
		idx += lsb(idx);
	}
}

int query2(int idx)
{
	ans = 0;
	while (idx <= k)
	{
		ans += ft2[idx];
		idx += lsb(idx);
	}
	return ans;
}

void update2(int idx, int val)
{
	while (idx > 0)
	{
		ft2[idx] += val;
		idx -= lsb(idx);
	}
}


int main()
{
	scanf("%i", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%i%i", &a, &b);
		points[i] = {a, -b};
		idx[points[i]] = i;
		v.insert(a), v.insert(b);
	}

	for (int i : v) val[i] = ++k;

	sort(points, points+n);
	for (i = n - 1; i >= 0; --i)
	{
		y[i] = val[-points[i].second];
		id[i] = idx[points[i]];
		contem[id[i]] = query1(y[i]); update1(y[i], 1);
	}

	for (i = 0; i < n; ++i)
	{
		contido[id[i]] = query2(y[i]); update2(y[i], 1);
		printf("%i ", contem[i]);
	}
	printf("\n");

	for (i = 0; i < n; ++i)
		printf("%i ", contido[i]);
	printf("\n");
}
