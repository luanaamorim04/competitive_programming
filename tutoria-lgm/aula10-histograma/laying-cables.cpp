#include <iostream>
#include <map>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, pi, pesq, esq[MAXN], resp[MAXN], dir[MAXN],pdir;
pair<int, int> arr[MAXN];
map<pair<int, int>, int> pos;

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		pos[arr[i]] = i;
	}
	sort(arr+1, arr+n+1);

	arr[0] = arr[n+1] = {0, 1e9 + 10};
	for (int i = 1; i <= n; i++)
	{
		esq[i] = i-1;
		while (arr[esq[i]].second <= arr[i].second) esq[i] = esq[esq[i]];
	}

	for (int i = n; i >= 1; i--)
	{
		dir[i] = i+1;
		while (arr[dir[i]].second <= arr[i].second) dir[i] = dir[dir[i]];
	}

	arr[0]  = {-1e9, -1e9};
	arr[n+1] = {1e9, -1e9};
	for (int i = 1; i <= n; i++)
	{
		pi = arr[i].first;
		pesq = arr[esq[i]].first;
		pdir = arr[dir[i]].first;
		if (pi-pesq < pdir-pi && esq[i]) resp[pos[arr[i]]] = (esq[i] ? pos[arr[esq[i]]] : -1);
		else if (pdir-pi < pi-pesq && dir[i] <= n) resp[pos[arr[i]]] = (dir[i] <= n ? pos[arr[dir[i]]]: -1); 
		else if (arr[esq[i]].second > arr[dir[i]].second) resp[pos[arr[i]]] = pos[arr[esq[i]]];
		else if (arr[dir[i]].second > arr[esq[i]].second) resp[pos[arr[i]]] = pos[arr[dir[i]]];
		else resp[pos[arr[i]]] = -1;
	}

	for (int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << endl;
}
