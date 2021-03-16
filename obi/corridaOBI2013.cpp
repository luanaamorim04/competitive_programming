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

double a, b, c, a1, b1, c1;

int main()
{_  
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    if (b / c < b1 / c1) cout << a;
    else cout << a1;
}