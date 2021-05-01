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

bitset<MAX> s;
string tmp;
set<par> pares;
multiset<int> resp;
par here, last, prox;
int n, x, l= '2', c, tam, ini, fim;

void remove(par x)
{
	resp.erase(resp.find((x.second)-(x.first)+1));
	pares.erase(x);
}

void add(par x)
{
	resp.insert((x.second)-(x.first)+1);
	pares.insert(x);
}

int main()
{_
	cin >> tmp;
	tmp.push_back('2');
	for (int i = 0; i < tmp.size(); i++)
		if (tmp[i] != l)
		{
			l = tmp[i];
			if (i)
			{
				pares.insert({c, i});
				resp.insert(i-c+1); 
			} 

			c = i + 1;
		}

	tam = tmp.size()-1;

	cin >> n;
	while (n--)
	{
		cin >> x;

		auto it = pares.lower_bound({x, 0});
		if (it == pares.end()) here = *(--it);
		else here = *it;
		prox = (it != prev(pares.end()) ? *next(it) : *it);
		last = (it != pares.begin() ? *prev(it) : *it);
		

		if (here.first == x && here.second == x)
		{
			ini = (here.first == 1 ? 1 : last.first);
			fim = (here.second == tam ? tam : prox.second);
			remove(here);
			if (here.first > 1) remove(last);
			if (here.second < tam) remove(prox);

			add({ini, fim});
		}
		else if (here.first == x) 
		{
			ini = (here.first == 1 ? 1 : last.first);
			fim = here.second;
			remove(here);
			if (here.first > 1) remove(last);

			add({ini, x});
			add({x+1, fim});
		}
		else if (last.second == x) 
		{
			ini = (x == 1 ? 1 : last.first);
			fim = here.second;
			remove(here);
			if (here.first > 1) remove(last);

			add({ini, x-1});
			add({x, fim});
		}
		else 
		{
			if (here.first > x) here = last;
			ini = here.first, fim = here.second;
			remove(here);
			add({x, x});
			add({ini, x-1});
			add({x+1, fim});
		}

		cout << (*resp.rbegin()) << ' ';
	}
	cout << endl;
}





