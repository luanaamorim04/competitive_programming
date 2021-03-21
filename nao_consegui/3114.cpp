#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
par p[1000001];

long long f(int idx)
{
    if (idx == n) return 1;
    cout << idx << endl;
    long long ans = 0;
    for (int i = idx + 1; i <= n; i++)
        if (p[i].second > p[idx].second) 
        {
            ans = ans + f(i);
        }

    return ans;
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].second >> p[i].first;

    sort(p+1, p+1+n);

    p[0].second = -1;
    cout << f(0) << endl;
}