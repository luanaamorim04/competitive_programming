#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x;
set<int> s;

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cout << (n - (int) s.size()) << endl;
}