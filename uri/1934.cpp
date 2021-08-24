#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long 

using namespace std;

ll n, m, freq_l[2600][101], freq_c[2600][101], soma_l[101], soma_c[101];
char a, b;

vector<pair<int, ll> > resp;
set<ll> linha[101], coluna[101], k;

int find_linha()
{
	for (int i = 0; i < n; i++)
		if (linha[i].size() == 1) return i;
	return -1;
}

int find_coluna()
{
	for (int j = 0; j < m; j++)
		if (coluna[j].size() == 1) return j;
	return -1;
}

void del(int letra, int val)
{
	for (int i = 0; i < n; i++)
	{
		soma_l[i] -= (freq_l[letra][i]*val);
		linha[i].erase(letra);
	}

	for (int j = 0; j < m; j++)
	{
		soma_c[j] -= (freq_c[letra][j]*val);
		coluna[j].erase(letra);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			int x = (a-'a')*100 + (b-'a');
			k.insert(x);
			if (!freq_l[x][i]) linha[i].insert(x);
			if (!freq_c[x][j]) coluna[j].insert(x);
			freq_l[x][i]++;
			freq_c[x][j]++;
		}

		cin >> soma_l[i];
	}

	for (int i = 0; i < m; i++)
		cin >> soma_c[i];

	int tot = k.size();
	while (resp.size() != tot)
	{
		if (find_linha() != -1)
		{
			int l = find_linha();
			int letra = (*linha[l].begin());
			ll val = soma_l[l]/freq_l[letra][l];
			resp.push_back({letra, val});	
			del(letra, val);
		}
		else
		{
			int c = find_coluna();
			int letra = (*coluna[c].begin());
			ll val = soma_c[c]/freq_c[letra][c];
			resp.push_back({letra, val});	
			del(letra, val);
		}
	}

	sort(resp.begin(), resp.end());
	for (auto [a, b] : resp)
		cout << (char)(((a-(a%100))/100)+'a') << (char)((a%100)+'a') << ' ' << b << endl;
}




