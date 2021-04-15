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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> letters;
set<par> maior_freq;
int freq[200], last, tot, menor_letra;
string s;

int main()
{_
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		freq[s[i]]++;

	tot = s.size();

	for (char c : s)
	{
		letters.insert(c);
		maior_freq.insert({freq[c], c});
	}

	par x = (*maior_freq.rbegin());
	if (x.first > (s.size() + 1)/2)
	{
		cout << -1 << endl;
		return 0;
	}

	while (tot--)
	{
		par x = (*maior_freq.rbegin());
		if (x.first == ((tot+3)>>1))
		{
			int letra = x.second;
			cout << (char) letra;
			last = letra;
			maior_freq.erase(x);
			if (!(--freq[letra]))
				letters.erase(letra);
			else
				maior_freq.insert({freq[letra], letra});
		
			continue;
		}

		menor_letra = (*letters.begin());
		if (last != menor_letra)
		{
			cout << (char) menor_letra;
			last = menor_letra;
			maior_freq.erase({freq[menor_letra], menor_letra});
			if (!(--freq[menor_letra]))
				letters.erase(menor_letra);
			else
				maior_freq.insert({freq[menor_letra], menor_letra});
		}
		else
		{
			menor_letra = (*(++letters.begin()));
			cout << (char) menor_letra;
			last = menor_letra;
			maior_freq.erase({freq[menor_letra], menor_letra});
			if (!(--freq[menor_letra]))
				letters.erase(menor_letra);
			else
				maior_freq.insert({freq[menor_letra], menor_letra});
		}	
	}

	cout << endl;
}








