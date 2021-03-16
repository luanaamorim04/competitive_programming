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

int main()
{_
    int a1, a2, b1, b2, x, y, ok = 0;
    cin >> x >> y;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 + a2 <= x && max(b1, b2) <= y) ok = 1;
    if (a1 + a2 <= y && max(b1, b2) <= x) ok = 1;
    if (b1 + b2 <= x && max(a1, a2) <= y) ok = 1;
    if (b1 + b2 <= y && max(a1, a2) <= x) ok = 1;
    if (a1 + b2 <= x && max(a2, b1) <= y) ok = 1;
    if (a1 + b2 <= y && max(a2, b1) <= x) ok = 1;
    if (b1 + a2 <= x && max(a1, b2) <= y) ok = 1;
    if (b1 + a2 <= y && max(a1, b2) <= x) ok = 1;
    cout << (ok ? "S\n" : "N\n");
}