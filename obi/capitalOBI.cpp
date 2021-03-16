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

double a[4];

int main()
{_  
    cin >> a[1] >> a[2] >> a[3] >> a[0];
    sort(a, a+4);
    if (a[3] / a[2] == a[1] / a[0]) cout << 'S' << endl;
    else if (a[3] / a[1] == a[2] / a[0]) cout << 'S' << endl;
    else if (a[3] / a[0] == a[2] / a[1]) cout << 'S' << endl;
    else cout << 'N' << endl;
}