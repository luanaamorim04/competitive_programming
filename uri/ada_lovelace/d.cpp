#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, b[202], a[202], ans, i, j;
set<par> s;

int mdc(int a, int b)
{
    if (b == 0) return a;
    return mdc(b, a%b);
}

int main()
{_
    while (cin >> n && n)
    {
        s.clear();
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < n; i++) cin >> b[i];

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (mdc(a[i], b[j]) == 1) 
                {
                    s.insert(make_pair(a[i], b[j]));
                    s.insert(make_pair(b[j], a[i]));
                }

        cout << s.size() << endl;
    }
}