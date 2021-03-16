#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int v, p, k;

int main()
{_
    cin >> v >> p;
    k = v%p;
    for (int i = 0; i < p; i++)
    {
        if (i < k) cout << v/p + 1 << endl;
        else cout << v/p << endl;
    }
}