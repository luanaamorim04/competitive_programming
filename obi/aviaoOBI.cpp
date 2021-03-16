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

long long f, c, e, b, total;

int main()
{_
    cin >> f >> c >> e >> b;
    total = c * (f - (e - 1));
    
    if (b <= total)
    {
        cout << ceil((double) b/c) + e - 1 << ' ' << (char) (b%c ? 64 + b%c :  64 + c) << endl;
    }
    else
    {
        cout << "PROXIMO VOO\n";
    }
}