#include <iostream>
#include <vector>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()

using namespace std;

int t;
string s;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		vector<pair<char, int> > up, down;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'b' && !down.empty()) down.pop_back();
			else if (s[i] == 'B' && !up.empty()) up.pop_back();
			else if (s[i] != 'b' && s[i] >= 'a') down.push_back({s[i], i});
			else if (s[i] != 'B' && s[i] <= 'Z') up.push_back({s[i], i});
		}

	    int i1 = 0, i2 = 0;	

		while (i1 < up.size() || i2 < down.size())
		{
			if (i1 == up.size()) 
			{
				cout << down[i2].first;
				i2++;
			}
			else if (i2 == down.size())
			{
				cout << up[i1].first;
				i1++;
			}
			else if (up[i1].second < down[i2].second)
			{
				cout << up[i1].first;
				i1++;
			}
			else
			{
				cout << down[i2].first;
				i2++;
			}
		}

		cout << endl;
	}
}	
