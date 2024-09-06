#include <iostream>
#include <stack>
#include <vector>
#define MAXN (int) (3e5 + 10)
#define ii pair<int, int> 

using namespace std;

int m, e[MAXN], tam[MAXN], pai[MAXN], n, q, a, b;
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

int32_t main()
{
	cin >> n >> m >> q;
	while (m--) cin >> a >> b;
	for (int i = 1; i <= n; i++) pai[i] = i, tam[i] = 1;

	stack<tuple<string, int, int> > pilha;
	while (q--)
	{
		cin >> op >> a >> b;
		pilha.push({op, a, b});
	}

	stack<string> resp;
	while (!pilha.empty())
	{
		auto[op, a, b] = pilha.top(); pilha.pop();
		if (op[0] == 'a') resp.push((find(a) == find(b) ? "YES" : "NO"));
		else join(a, b);	
	}

	while (!resp.empty())
	{
		cout << resp.top() << endl;
		resp.pop();
	}
}

