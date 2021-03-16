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

int n, x;
string s[109];

int main()
{_
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s+n);
    cout << s[x-1] << endl;
}