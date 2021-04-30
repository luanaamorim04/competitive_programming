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
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bitset<MAX> resp, passou;
vector<int> grafo[MAX], nums;
int n, tam, m, a, b, freq[MAX], idx;

void dfs(int u)
{
	tam++;
	passou[u] = 1;
	for (int v : grafo[u])
		if (!passou[v]) dfs(v);
}

int main()
{_
	cin >> m >> n;
	resp[0] = true;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= m; i++)
	{
		if (!passou[i])
		{
			dfs(i);
			freq[tam]++;
			tam^=tam;
		}
	}

	for (int i = 1; i < MAX; i++)
	{
		idx = 1;
		while (freq[i])
		{
			nums.push_back(idx*i);
			freq[i] -= idx;
			if (freq[i] >= idx<<1) idx <<= 1;
			else idx = freq[i];
		}
	}

	for (int i = 0; i < nums.size(); i++)
		resp |= (resp<<nums[i]);

	for (int i = 1; i <= m; i++)
		cout << resp[i];
	cout << endl;
}
