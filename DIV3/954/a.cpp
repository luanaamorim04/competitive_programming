#include <iostream>
#include <vector> 
#include <queue>
#include <set>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (1e5 + 10)
#define INF (int) (1e18)
#define int long long
#define all(x) x.begin(), x.end()
#define ii pair<int, char>
#define MOD (int) (1e9 + 7)
#define _ cin.tie(0)->sync_with_stdio(0);

using namespace std;

int t, n, k, pref[MAXN], suff[MAXN], arr[MAXN];
vector<int> grafo[MAXN];
map<int, int> mapa;

int dobra(vector<int> v) // adjacentes menos i 
{
	int resp = INF;
	int tam = v.size();
	if (tam&1)
	{
		suff[tam-1] = 0;
		for (int i = 1; i < tam; i++)
		{
			pref[i] = pref[i-1];
			if (i&1) pref[i] += abs(v[i]-v[i-1]);
		}
		for (int i = tam-2; i >= 0; i--)
		{
			suff[i] = suff[i+1];
			if (i&1) suff[i] += abs(v[i]-v[i+1]);
		}

		resp = min(pref[tam-2], suff[1]);
		for (int i = 1; i < tam-1; i++)
			resp = min(resp, pref[i-1] + suff[i+1] + ((i&1) ? abs(v[i+1]-v[i-1]) : 0ll));
	}	
	else
	{
		resp = 0;
		for (int i = 1; i < tam; i+=2)
			resp += abs(v[i]-v[i-1]);
	}
	return resp;
}


int32_t main()
{_
	cin >> t;
	while (t--)
	{
		int resp = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			mapa[(arr[i]%k)] = i;
		}
		
		sort(arr, arr+n);
		for (int i = 0; i < n; i++)
			grafo[mapa[(arr[i]%k)]].push_back(arr[i]);

		int d = 0;
		for (auto[chave, valor] : mapa)
		{
			int i = valor;
			d += (grafo[i].size()&1);
			if (grafo[i].size() > 1) resp += dobra(grafo[i]);
			grafo[i].clear();
		}

		if (d > 1) cout << -1 << endl;
		else cout << resp/k << endl;
	}
}
