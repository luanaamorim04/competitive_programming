#include <iostream> 
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int n, c, qa, qb, q, resp;
string s;

void del(int idx)
{
	if (s[idx] == 'a') q -= qb, qa--; 
	if (s[idx] == 'b') qb--;
}

void add(int idx)
{
	if (s[idx] == 'b') q += qa, qb++;
	if (s[idx] == 'a') qa++;
}

int32_t main()
{
	cin >> n >> c >> s;
	int l = 0;
	for (int r = 0; r < s.size(); r++)
	{
		add(r);
		while (q > c) del(l++);
		resp = max(resp, r-l+1);
	}
	cout << resp << endl;
}
