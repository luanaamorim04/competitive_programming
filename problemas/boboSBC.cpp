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

int n, maxn, x, k;

int main()
{_  
    cin >> n >> k;
    maxn = k;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        maxn = max(maxn, x);
    }

    cout << (k == maxn ? 'S' : 'N') << endl;
}