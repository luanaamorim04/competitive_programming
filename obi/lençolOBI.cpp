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

int a1, a2, b1, b2, a, b, ok;

int main()
{_  
    cin >> a1 >> b1 >> a2 >> b2 >> a >> b;
    if (a1 >= a && b1 >= b) ok = 1;
    else if (a1 >= b && b1 >= a) ok = 1;
    else if (a2 >= a && b2 >= b) ok = 1;
    else if (a2 >= b && b2 >= a) ok = 1;
    else if (a1 + b2 >= a && min(a2, b1) >= b) ok = 1;
    else if (a1 + a2 >= a && min(b2, b1) >= b) ok = 1;
    else if (b1 + a2 >= a && min(a1, b2) >= b) ok = 1;
    else if (b1 + b2 >= a && min(a2, a1) >= b) ok = 1;
    else if (a1 + b2 >= b && min(a2, b1) >= a) ok = 1;
    else if (a1 + a2 >= b && min(b2, b1) >= a) ok = 1;
    else if (b1 + a2 >= b && min(a1, b2) >= a) ok = 1;
    else if (b1 + b2 >= b && min(a2, a1) >= a) ok = 1;
    cout << (ok ? 'S' : 'N') << endl;
}