#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

int n, k;

int find(string s, string w)
{
	for (int i = 0; i <= n-w.size(); i++)
	{
		int t = 1;
		for (int j = i; j < i+w.size(); j++)
		{
			t &= (s[j] == w[j-i]);
		}

		if (t) return 1;
	}
	return 0;
}


int main()
{
	string teste;
	//string s = "YQSEXDKXDVBMCKY XMQSDRUY MXB KOYN OCMNX X K OYKMKSVR OV VDWOBDOOZZXQV K RKIKO Y  DNYXMSDV JBI!S Y SZOKBEW";
	string ss, t,  s = "YQSEXDKXDVBMCKY XMQSDRUY MXB KOYN OCMNX X K OYKMKSVR OV VDWOBDOOZZXQV K RKIKO Y  DNYXMSDV JBI!S Y SZOKBEW";
	cin >> k >> teste;
	n = 105;
	t = s;
	ss = s;
	vector<int> v;
	for (int i = 1; i <= k; i++)
		v.push_back(i);
	do
	{
			for (int b = 0; b < n; b+=k)
			{
				for (int i = b; i < b+k; i++)
				{
					ss[i] = s[v[i % k] - 1 + b];
				}
			}

			int ok = 1;
			for (int i = 0; i < n-1; i++)
				if (ss[i] == '!' && ss[i+1] != ' ') ok = 0;
	
			for (int i = 0; i < 27; i++)
			{
				for (int j = 0; j < n; j++)
				{
					t[j] = ss[j];
					if (ss[j] != '!' && ss[j] != ' ')	
						t[j] = (char)((((int)ss[j] - '@' + i + 27) % 27) + '@');
				}
				if (find(t, teste)) cout << t << endl;
			}
	} while(next_permutation(all(v)));
	cout << "original" << endl;
	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << endl;
	cout << n << endl;
	cout << t << endl;
}
