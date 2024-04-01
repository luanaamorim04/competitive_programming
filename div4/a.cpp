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

int t, n, arr[MAXN], a, b, c;
string s;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		if (a < b && b < c) cout << "STAIR" << endl;
		else if (a < b && b > c) cout << "PEAK" << endl;
		else cout << "NONE" << endl;
				
	}
}	
