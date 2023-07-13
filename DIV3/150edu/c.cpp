#include <iostream>
#define MAXN 

using namespace std;

int t, n, val[200];
string s;

int32_t main()
{
	cin >> t;
	val['A'] = 1;
	val['B'] = 10;
	val['C'] = 100;
	val['D'] = 1000;
	val['E'] = 10000;
	while (t--)
	{
		cin >> s;
		int idx = 0, maior = 0, resp = 0;
		while (s[idx] == 'E')
			idx++;
		s[idx] = 'E';

		for (int i = s.size() - 1; i >= 0; i--)
		{
			maior = max(maior, (int)s[i]);
			if (maior > s[i]) resp -= val[s[i]];
			else resp += val[s[i]];
				
		}

		cout << resp << endl;

	}
}