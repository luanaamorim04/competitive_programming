#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, k;
int memo[100009];

int cmp(string a, string b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] - '0' > b[i] - '0') return 1;
        else if (b[i] - '0' > a[i] - '0') return 0;
    }

    return 0;
}

int f(int idx)
{
    if (memo[idx] != -1) return memo[idx];
    int ans = 0;
    string num;
    for (int i = idx; i < s.size(); i++)
    {
        num = num + s[i];
        if (s[i + 1] == '0') continue;
        if (cmp(num, k)) break;
        ans = (ans + f(i + 1)) % MOD;
    }   
    
    return memo[idx] = ans ? ans : cmp(k, num);
}

int main()
{_  
    cin >> k >> s;
    for (int i = 0; i <= s.size(); i++)
        memo[i] = -1;
    cout << f(0) << endl;
}