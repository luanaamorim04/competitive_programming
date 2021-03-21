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

map<int, int> freq;
int n, arr[1<<20], l, r, resp;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (r < n)
    {
        while (freq.count(arr[r]))
        {
            freq[arr[l]]--;
            if (!freq[arr[l]]) freq.erase(arr[l]);
            l++;
        }

        resp = max(resp, r-l+1);
        freq[arr[r]]++, r++;
    }

    cout << resp << endl;
}
