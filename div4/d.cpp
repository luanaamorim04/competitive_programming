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
vector<int> v;

int32_t main()
{
	cin >> t;
	for (int i = 0; i <= (1<<5); i++)
	{
		int num = 0, base = 1;
		for (int j = 0; j <= 5; j++)
		{	
			if (i&(1<<j)) num += (base);
			base *= 10;
		}
		if (num < MAXN)v.push_back(num);
	}
	for (int x = 0; x < 6; x++)
	for (int i : v)
	{
		for (int j : v)
		{
			if (i*j >= MAXN || arr[i*j]) continue;
			arr[i*j] = 1;
			v.push_back(i*j);
		}
	}

	while (t--)
	{
		cin >> n;
		cout << (arr[n] ? "YES" : "NO") << endl;
	}
}	
