#include <iostream>
#define MAXN 16777216
 
using namespace std;
 
int n, arr, dp[MAXN];
string s;
 
int32_t main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
	{
        cin >> s;
		arr = 0;
        for (int j = 0; j < 3; j++)
            arr |= (1<<(s[j]-'a'));
 
		dp[(~arr)&((1<<24) - 1)]++;
	}
 
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < (1<<24); j++)
			if ((~j)&(1<<i)) dp[j] += dp[j^(1<<i)];
 
    long long resp = 0;
	for (int i = 0; i < (1<<24); i++)
	{
		resp ^= ((long long)(n-dp[i])*(long long)(n-dp[i]));
	}
 
    cout << resp << endl;
}
