#include <iostream>
#include <vector> 
#include <set>
#define MAXN (int) (3e5 + 10)

using namespace std;

int op, a, b, n, m, pai[MAXN], tam[MAXN], maior[MAXN], menor[MAXN];
set<int> rep;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	if (A == B) return;
	if (A < B) swap(A, B);
	pai[B] = A;
	rep.erase(B);
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		rep.insert({i, i}), pai[i] = i;
	
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
			auto l = rep.lower_bound({a, 0});
			auto r = rep.lower_bound({b, 0});
			if (r == rep.end()) continue;
			while (l != r)
			{
				auto nxt = l;
				nxt++;
				join((*l), (*nxt));
				l = nxt;
			}
		}
		else
		{
			cout << (find(a) == find(b) ? "YES" : "NO") << endl;
		}
	}
}

