#include <iostream> 
#include <vector>
#include <stack> 
#define int long long
#define ii pair<int, int> 
#define MAXN (int)(2e5 + 10)

using namespace std;

int n, arr[MAXN];
stack<ii> p, p1;

int mdc(int a, int b)
{
	if (b == 0) return a;
	return mdc(b, a%b);
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int resp = 1e9, l = 1;
	for (int r = 1; r <= n; r++)
	{
		if (arr[r] == 1)
		{
			cout << 1 << endl;
			return 0;
		}
		p.push({arr[r], 1});
		while (!p.empty())
		{
			auto[g, f] = p.top(); p.pop();
			if (!p1.empty() && p1.top().first == mdc(g, arr[r])) 
			{
				auto[g1, f1] = p1.top(); p1.pop();
				p1.push({g1, f1+f});
			}	
			else
			{
				p1.push({mdc(g, arr[r]), f});
			}
		}

		ii last = p1.top(); p1.pop();
		while (!p1.empty() && last.first == 1)
		{
			auto[g, f] = p1.top(); 
			if (g != 1) 
			{
				l += last.second - 1;
				last.second = 1;
				break;
			}


			l += last.second;
			last = p1.top(); p1.pop();
		}

		p.push(last);
		if (last.first == 1) resp = min(resp, (r-l+1));
		while (!p1.empty())	
		{
			p.push(p1.top()); p1.pop();
		}
	}

	cout << (resp == 1e9 ? -1 : resp) << endl;
}
