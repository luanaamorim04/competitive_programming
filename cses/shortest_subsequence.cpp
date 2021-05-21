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
#define MAX (int) (1<<20) -  1
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, s1;
int ft[1<<20][4], maxn, last[1<<20][4], a, c, g, t, r, idx, val['T' + 1];

int query(int idx, int c)
{
	int ans = 0;
	while (idx > 0)
	{
		ans = max(ans, ft[idx][c]);
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, int val, int c)
{
	while (idx <= MAX)
	{
		ft[idx][c] = max(ft[idx][c], val);
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> s;
	val['T'] = 3, val['C'] = 1, val['G'] = 2;
	for (int i = 1; i <= s.size(); i++)
	{
		a = query(i, 0), c = query(i, 1), g = query(i, 2), t = query(i, 3);
		maxn = min(min(a, c), min(g, t)) + 1;

		update(i+1, maxn, val[s[i-1]]);
		last[i][0] = last[i-1][0];
		last[i][1] = last[i-1][1];
		last[i][2] = last[i-1][2];
		last[i][3] = last[i-1][3];
		last[i][val[s[i-1]]] = i;
	}

	idx = s.size() + 1;
	r = 1;

	while (r)
	{
		a = query(idx, 0), c = query(idx, 1), g = query(idx, 2), t = query(idx, 3);	
		r = min(min(a, c), min(g, t));

		if (a == r)
		{
			s1 += 'A';
			idx = last[idx-1][0];
		} 
		else if (c == r)
		{
			s1 += 'C';
			idx = last[idx-1][1];
		} 
		else if (g == r)
		{
			s1 += 'G';
			idx = last[idx-1][2];
		} 
		else 
		{
			s1 += 'T';
			idx = last[idx-1][3];
		} 
	}

	reverse(all(s1));
	cout << s1 << endl;
}	










