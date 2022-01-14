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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, q, a, b, pai[MAX], maior, menor, freq[MAX], tam[MAX];

int find(int x)
{
	if (x==pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b) return;
	pai[b] = a;
	freq[tam[a]]--;
	freq[tam[b]]--;
	tam[a] += tam[b];
	freq[tam[a]]++;
	maior = max(maior, tam[a]);
	while (!freq[menor])
	{
		menor++;
	}
}	

int main()
{_
	cin >> n >> q;
	freq[1] = n;
	maior = menor = 1;
	for (int i = 1; i <= n; i++) tam[i] = 1, pai[i] = i;

	while (q--)
	{
		cin >> a >> b;
		join(a, b);
		cout << maior - menor << endl;
	}
}







