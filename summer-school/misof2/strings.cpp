//#include <bits/stdc++.h> 
#include <iostream>
#define int long long
#define MAXN (int) (1e5)
#define INF (int) (1e9)

using namespace std;

int n;

int32_t main()
{	
	cin >> n;
//`	if (n == 1)
//`	{
//`		cout << "ab" << endl;
//`		cout << "ba" << endl;
//`		return 0;
//`	}
	for (int i = 0; i < 2*n; i++)
		cout << (char)('a' + (i>=n));
	cout << endl;
	for (int i = 0; i < 2*n; i++)
	{
		if (i == n-1) cout << 'b';
		else if (i == n) cout << 'a';
		else cout << (char)('a' + (i>=n));
	}
	cout << endl;
}
