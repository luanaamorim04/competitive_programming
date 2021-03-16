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

int n, x;
string bi;
vector<int> ans;

int fexpo(int a, int b, int k)
{
    int ans = 1;
    while (b)
    {
        if (b % 2) ans = (ans * a) % x;
        a = (a * a) % x;
        b /= 2;
    }

    return ans % x;
}

int divisivel(int x)
{
    int n = 0;
    for (int i = 0; i < bi.size(); i++)
    {
        if (bi[i] - '0') n = (n + fexpo(2, bi.size() - 1 - i, x)) % x;
    }

    return !n;
}

int main()
{_  
    cin >> bi >> n;
    while (n--)
    {
        cin >> x;
        if (divisivel(x)) ans.push_back(x);
    }
    if (ans.size() < 1)
    {
        cout << "Nenhum" << endl;
        return 0;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ' ';
    }

    cout << endl;
}