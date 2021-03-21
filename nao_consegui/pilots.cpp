#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, arr[3*(1<<20)];
set<int> cj;
set<int>::iterator it;

int main()
{_
    it = cj.end();
    it--;

    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << *it << endl;
}