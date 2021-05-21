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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define K 300
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, arr[MAX], c, d, ans, resp[MAX], freq[MAX], cp[MAX], maxn;
map<int, int> mapa;

struct Query
{
	int a, b, idx;
};

Query q[MAX];

int cmp(Query q1, Query q2)
{
	if (q1.a/K != q2.a/K) return q1.a < q2.a;
	return (((q1.a/K) & 1) ? (q1.b < q2.b) : (q1.b > q2.b));
	//return q1.b < q2.b;
}

void remove(int idx)
{
	freq[arr[idx]]--;
	ans -= (!freq[arr[idx]]); 
}

void add(int idx)
{
	ans += (!freq[arr[idx]]);
	freq[arr[idx]]++;
}

int main()
{_
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (!mapa.count(arr[i])) mapa[arr[i]] = ++maxn;
		arr[i] = mapa[arr[i]];
	}


	for (int i = 0; i < m; i++)
	{
		cin >> c >> d;
		q[i] = {c-1, d-1, i};
	}

	sort(q, q+m, cmp);

	int ini = 0, fim = -1;
	for (int i = 0; i < m; i++)
	{
		while (ini > q[i].a)
			add(--ini);

		while (ini < q[i].a)
			remove(ini++);

		while (fim > q[i].b)
			remove(fim--);

		while (fim < q[i].b)
			add(++fim);

		resp[q[i].idx] = ans;
	}

	for (int i = 0; i < m; i++)
		cout << resp[i] << endl;
}

























