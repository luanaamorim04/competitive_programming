#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
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

set<par> cj;
int arr[1<<20], n, k, x;
map<int, int> freq;

int main()
{_
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
        
    int l = 1, r = 1;
    ll resp = 0;
    cj.insert(par(-1, arr[1]));
    freq[arr[1]] = 1;
    while (r <= n)
    {
        if (-((*cj.begin()).first) < k) 
        {
            r++;
            cj.erase(par(-freq[arr[r]], arr[r]));
            freq[arr[r]]++;
            cj.insert(par(-freq[arr[r]], arr[r]));
        }

        while (-((*cj.begin()).first) >= k)
        {
            cj.erase(par(-freq[arr[l]], arr[l]));
            freq[arr[l]]--;
            cj.insert(par(-freq[arr[l]], arr[l]));
            l++;
            resp += (n - r + 1);
        }
    }

    cout << resp << endl;
}