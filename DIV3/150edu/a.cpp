#include <iostream>
#define MAXN 

using namespace std;

int t, n;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int qtd = 0;
		while (n)
		{
			n>>=1;
			qtd += n;
		}

		// cout << qtd << endl;

		cout << (qtd%2==0 ? "Alice" : "Bob") << endl;
	}
}