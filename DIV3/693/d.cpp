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
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, t, x, s1, s2, vez, ib, ia;
vector<int> odd, even;

int main()
{_  
    cin >> t;
    while (t--)
    {
        cin >> n;
        s1 = s2 = vez = 0;
        ib = ia = n - 1;
        odd.clear();
        even.clear();
        while (n--)
        {
            cin >> x;
            if (x & 1) odd.push_back(x), even.push_back(0);
            else even.push_back(x), odd.push_back(0);
            ((x & 1) ? s2 : s1) += x; 
        }

        sort(all(odd));
        sort(all(even));
        while (ia >= 0 && ib >= 0)
        {
            if (vez)
            {
                if (ia >= 0 && even[ia] > odd[ib]) s1 -= even[ia--];
                else if (ib >= 0) --ib;
            }
            else
            {
                if (ib >= 0 && odd[ib] > even[ia]) s2 -= odd[ib--];
                else if (ia >= 0) --ia;
            }
            vez ^= 1;
        }

        cout << (s1 > s2 ? "Alice" : (s1 == s2 ? "Tie" : "Bob")) << endl;
    }
}
