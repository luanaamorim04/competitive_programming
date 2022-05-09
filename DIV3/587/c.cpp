#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[200001], k, a[3], b[3], c[3], d[3];

int cobriu(int x1, int y1, int x2, int y2)
{
    if (x1 <= a[0] && y1 <= b[0] && x2 >= c[0] && y2 >= d[0]) return 1;
    return 0;
}

int vertical(int y1, int y2)
{
    if (y1 <= b[0] && y2 >= d[0]) return 1;
    return 0;
}

int hor(int x1, int x2)
{
    if (x1 <= a[0] && x2 >= c[0]) return 1;
    return 0;
}

int main()
{_  
    for (int i = 0; i < 3; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    if (cobriu(a[1], b[1], c[1], d[1]) || cobriu(a[2], b[2], c[2], d[2]))
        cout << "NO" << endl;
    else if (vertical(b[1], d[1]) && vertical(b[2], d[2]) && min(c[1], c[2]) >= max(a[1], a[2]) && min(a[1], a[2]) <= a[0] && max(c[2], c[1]) >= c[0])
        cout << "NO" << endl;
    else if (hor(a[1], c[1]) && hor(a[2], c[2]) && min(d[1], d[2]) >= max(b[1], b[2]) && min(b[1], b[2]) <= b[0] && max(d[2], d[1]) >= d[0])
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
}