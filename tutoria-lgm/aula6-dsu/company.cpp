#include <iostream>
#include <vector> 
#include <set>
#define MAXN (int) (2e5 + 10)
#define ii pair<int, int> 

using namespace std;

int op, a, b, n, m, pai[MAXN], tam[MAXN];
set<ii> intervalo[MAXN];

void add(int l, int r, set<ii> &cj)
{
	auto it = cj.lower_bound({l+1, 0});
	if (it != cj.begin() && (*(--it)).second >= l-1 && (*it).first <= l) 
	{
		l = min(l, (*it).first);
		r = max(r, (*it).second);
		cj.erase(it);
	}

	it = cj.upper_bound({r, n});
	if ((*it).first <= r+1 && (*it).second > r)
	{
		l = min(l, (*it).first);
		r = max(r, (*it).second);
		cj.erase(it);
	}

	cj.insert({l, r});
}

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int join(int a, int b)
{
	if (a == b) return a;
	if (tam[a] < tam[b]) swap(a, b);
	pai[b] = a;
	tam[a] += tam[b];
	for (auto[i, j] : intervalo[b])
		add(i, j, intervalo[a]);
	return a;
}


int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		intervalo[i].insert({i, i}), pai[i] = i, tam[i] = 1;
	
	while (m--)
	{
		cin >> op >> a >> b;
		if (op == 1)
		{
			int A = find(a), B = find(b);
			join(A, B);
		}
		else if (op == 2)
		{
			int A = find(a);
			auto it = intervalo[A].lower_bound({a+1, 0}); --it;
			int l = (*it).first, r = (*it).second;
			while (r < b)
			{
				int B = find(r+1);
				auto itt = intervalo[B].lower_bound({r+2, 0}); --itt;
				r = (*itt).second;
				A = join(A, B);
			}
		}
		else
		{
			cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
		}
	}
}
