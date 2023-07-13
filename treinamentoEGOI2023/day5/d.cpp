// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define int long long
#define all(x) x.begin(), x.end()
#define MAXN (int) (1e3 + 5)
#define INF 1e9 + 7

using namespace std;

int n, k, arr[MAXN], resp, a, b, ini;
vector<tuple<int, int, int> > v;

// int pode(int x)
// {
// 	priority_queue<int, vector<int>, greater<int> > pq;
// 	for (auto[l, r, idx] : v)
// 	{
// 		pq.push(r);
// 		while (!pq.empty() && pq.top() < l+x) pq.pop();
// 		if (pq.size() >= k) return l;
// 	}

// 	return 0;
// }

int32_t main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		v.push_back({a, b, i});
	}

	sort(all(v));

	for (auto[l, r, idx] : v)
	{
		for (int i = l; i <= r; i++)
			arr[i]++;
		for (int tam = 400; tam >= 1; tam--)
			if (arr[l+tam] >= k && resp < tam) resp = tam, ini = l; 
	}

	// int ini = 1, meio, fim = INF;
	// while (ini <= fim)
	// {
	// 	meio = (ini+fim)>>1;
	// 	if (pode(meio)) ini = meio + 1;
	// 	else fim = meio - 1;
	// }

	cout << resp << endl;
	// int i = pode(ini - 1);
	vector<int> vv;
	for (auto[l, r, idx] : v)
	{
		if (l <= ini && r >= ini+resp)
			vv.push_back(idx);
	}

	sort(all(vv));
	for (int x : vv)
		cout << x << ' ';

	cout << endl;
}







