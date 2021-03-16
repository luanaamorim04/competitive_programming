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

int p[10], x, ok;

int main()
{_
    for (int i = 0; i < 8; i++)
    {
        cin >> x;
        p[x]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (p[i] > 4) ok = 1;
    }

    cout << (ok ? 'N' : 'S') << endl;
}