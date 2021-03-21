#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b;

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (a < b) swap(a, b);
        if ((a+b) % 3 == 0 && (a-b) <= (a+b)/3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
