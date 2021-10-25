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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (1e6 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl;
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, p;
ll h1[MAX], h2[MAX], a1[MAX], a2[MAX], A1, A2, B, s1, s2, p1, p2, tam, ans;

int main()
{_
	cin >> s >> p;	
	B = MOD;
	A1 = 911382323;
	A2 = 972663749;
	a1[0] = a2[0] = 1;
	for (int i = 1; i < MAX; i++)
	{
		a1[i] = (a1[i-1]*A1) % B;
		a2[i] = (a2[i-1]*A2) % B;
	}	

	h1[1] = (a1[sz(s)-1]*(s[0]-'a')) % B;
	h2[1] = (a2[sz(s)-1]*(s[0]-'a')) % B;
	for (int i = 1; i < sz(s); i++)
	{	
		h1[i+1] = (h1[i] + (a1[sz(s)-(i+1)]*(s[i]-'a'))) % B;
		h2[i+1] = (h2[i] + (a2[sz(s)-(i+1)]*(s[i]-'a'))) % B;
	}

	s1 = (a1[sz(p)-1]*(p[0]-'a')) % B;
	s2 = (a2[sz(p)-1]*(p[0]-'a')) % B;
	for (int i = 1; i < sz(p); i++)
	{
		s1 = (s1 + (a1[sz(p)-(i+1)]*(p[i]-'a'))) % B;
		s2 = (s2 + (a2[sz(p)-(i+1)]*(p[i]-'a'))) % B;
	}

	for (int i = 1; i <= sz(s); i++)
	{
		tam = (sz(s)-(i-1)) - sz(p);
		if (tam < 0) break;
		p1 = (h1[i+sz(p)-1] - h1[i-1] + B) % B;
		p2 = (h2[i+sz(p)-1] - h2[i-1] + B) % B;
		ans += ((s1*a1[tam])%B == p1 && (s2*a2[tam])%B == p2);
	}	

	cout << ans << endl;
}	



















