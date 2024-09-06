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
#define BASE 37

using namespace std;

int layer, dois, um, zero, t, n, e[MAXN], h[MAXN];
string s;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> dois >> um >> zero;
		if (dois+1 != zero)
		{
			cout << -1 << endl;
			continue;
		}

		int h = 0, cur = 1, last = 0;
		while (dois >= cur)
		{
			dois -= cur;
			last = cur;
			cur *= 2;
			h++;
		}
		h += (dois != 0);
		
		layer = last*2 - dois;
		if (layer == zero) layer = 0;
		if (um <= layer) cout << h << endl;
		else cout << h + (um-layer+zero-1)/zero << endl;
	}
}	
