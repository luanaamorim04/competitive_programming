// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#define MAXN (int) (2e5 + 4)
#define int long long
#define INF (1e9 + 7)
#define bug(x) cout << bitset<52>(x) << ": " << #x << endl;

using namespace std;

int t, n, arr[MAXN], resp, letras, pares_, tem[MAXN];
string s;
unordered_map<int, int> mapa;

// void tabela()
// {
// 	for (char i = 'z'; i >= 'a'; i--)
// 		cout << i;
// 	for (char i = 'z'; i >= 'a'; i--)
// 		cout << i;
// 	cout << endl;
// }

int32_t main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i] ^= (1LL<<(s[j]-'a'));
			tem[i] |= (1LL<<(s[j]-'a'));
		}
	}

	pares_ = (1LL<<26) - 1;
	letras = ((1LL<<52) - 1) ^ ((1LL<<26) - 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 25; j++)
		{
			if (tem[i]&(1LL<<j)) continue;
			pares_ ^= (1LL<<j);
			letras ^= (1LL<<(26+j));
			resp += mapa[(arr[i]^pares_) | letras];
			mapa[arr[i] | letras]++;
			pares_ ^= (1LL<<j);
			letras ^= (1LL<<(26+j));
		}
	}

	printf("%lld\n", resp);
}
// 8=D