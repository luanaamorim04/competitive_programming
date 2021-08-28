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
#define MAX (int) (2e6 + 5)
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

ll a, b, q1, q2, k, resp, comp[MAX];
vector<int> primos[MAX];
int pilha[MAX];

int main()
{_
	cin >> a >> b;
	for (int i = 2; i <= b; i++)
	{	
		if (!comp[i])
		{
			for (int j = i; j <= b; j+=i)
			{
				primos[j].push_back(i);
				comp[j] = 1;
			}
		}

		int x = i;
		if (x >= a)
		{
			for (int p : primos[i])
			{
				while (x%p == 0)
				{
					pilha[p]++;
					x/=p;
				}
			}
		}
	}

	for (int i = 1; i <= b; i++)
		resp ^= pilha[i];

	cout << (resp?"Chico":"Didigo") << endl;
}





