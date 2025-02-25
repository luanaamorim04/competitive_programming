#include <iostream>
#define MAXN (int) (3e5 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, op, a, b, tam[MAXN], pai[MAXN], dist[MAXN];

ii find(int x)
{
	if (x == pai[x]) return {x, dist[x]}; 
	ii tmp = find(pai[x]);
	pai[x] = tmp.first;
	dist[x] += tmp.second;
	return {pai[x], dist[x]};
}

void join(int a, int b)
{
	int A = find(a).first, B = find(b).first;
	dist[A] = 1;
	pai[A] = B;
}

int solve(int x)
{
	find(x);
	int r = 0;
	while (x != pai[x])
	{
		r += dist[x];
		x = pai[x];
	}

	return r + dist[x];
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) pai[i] = i, tam[i] = 1;
	while (m--)
	{
		cin >> op;
		if (op == 1 && cin >> a >> b) join(a, b);
		else if (op == 2 && cin >> a) cout << solve(a) << endl;
	}
}

