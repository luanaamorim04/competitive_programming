#include <iostream>
#define MAXN (int) (3e5 + 10)
#define int long long

using namespace std;

int n, pode[30], freq[30], arr[MAXN], resp, soma, val[MAXN], tmp;
string s, m;

int estoura()
{
	for (int i = 0; i < 26; i++) if (freq[i] > pode[i]) return 1;
	return 0;
}

int32_t main()
{
	cin >> soma >> soma;
	cin >> s >> m;
	for (char c : m) pode[c-'a']++;

	int l = 0;
	for (int r = 0; r < s.size(); r++)
	{
		freq[s[r]-'a']++;
		while (estoura()) freq[s[l]-'a']--, l++;


		resp += (r-l+1);
	}

	cout << resp << endl;
}



