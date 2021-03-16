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
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int h, l, a, b, c, ok;

int main()
{_
    cin >> a >> b >> c >> h >> l;
    if (a <= h && b <= l) ok = 1;
    if (b <= h && a <= l) ok = 1;
    if (c <= h && b <= l) ok = 1;
    if (b <= h && c <= l) ok = 1;
    if (a <= h && c <= l) ok = 1;
    if (c <= h && a <= l) ok = 1;

    cout << (ok ? 'S' : 'N') << endl;
}