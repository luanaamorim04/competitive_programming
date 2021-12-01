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
#define MAX (int) (1e5 + 10)
#define P (-1e9)
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

double n, a, arr[MAX], soma;

double p(double h)
{
	double resp = 0;
	for (int i = 0; i < n; i++)
		resp += max((double) 0, arr[i]-h);

	return resp;
}

double bb()
{
	double ini = 0, meio, fim = 1e4;
	int cnt = 1000;
	while (cnt--)
	{
		meio = ((fim+ini)/2);
		if (p(meio) >= a) ini = meio;
		else fim = meio; 
	}

	return meio;
}

int main()
{_
	while (cin >> n >> a && n)
	{
		soma = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			soma += arr[i];
		}

		if (soma == a) cout << ":D" << endl;
		else if (soma < a) cout << "-.-" << endl;
		else cout << fixed << setprecision(4) << bb() << endl;
 	}
}













