#include <iostream>
#include <vector>
#define MAXN (int) (3e5 + 10)
#define ii pair<int, int> 

using namespace std;

int e[MAXN], tam[MAXN], pai[MAXN], n, q, a, b;
string op;

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	if (A == B) return;
	if (tam[A] < tam[B]) swap(A, B);
	pai[B] = A;
	e[B] -= e[A];
	tam[A] += tam[B];
}

int valor(int a)
{
	int u = a, r = 0;
	while (u != pai[u])
	{
		r += e[u];
		u = pai[u];
	}	
	return r + e[pai[u]];
}

int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) pai[i] = i, tam[i] = 1;

	vector<int> resp;
	while (q--)
	{
		cin >> op;
		if (op[0] == 'j' && cin >> a >> b) join(a, b);
		else if (op[0] == 'a' && cin >> a >> b) e[find(a)] += b;
		else if (op[0] == 'g' && cin >> a) resp.push_back(valor(a));
	}

	for (int x : resp) cout << x << endl;

}
