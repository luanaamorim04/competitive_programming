#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define all(x) x.begin(), x.end()
#define ii pair<int, int> 
#define INF (int) (1e9)
#define MOD (int) (1e9 + 7)
#define iii tuple<int, int, int> 

using namespace std;

int t, n, arr[MAXN];
string s;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		int hora = ((s[0]-'0')*10) + (s[1] - '0');
		string min;
		min += s[3];
		min += s[4];
		if (hora >= 12)
		{
			if (hora != 12 && hora - 12 < 10) cout << "0";
			cout << (hora == 12 ? hora : hora - 12) << ":"<< min << " PM" << endl;
		}
		else
		{
			if (hora < 10 && hora > 0) cout << "0";
			cout << (hora==0?12:hora) << ":" << min << " AM" << endl;
		}
		
	}
}	
