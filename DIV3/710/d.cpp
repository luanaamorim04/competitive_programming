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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

priority_queue<int> pq;
map<int, int> freq;
int t, n, arr[1<<20], resp;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq.count(arr[i])) pq.push(freq[arr[i]]);
            freq.erase(arr[i]);
        }

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a > 1) pq.push(a - 1);
            if (b > 1) pq.push(b - 1);
            ++resp;
        }

        cout << n - 2*resp << endl;
        if (pq.size() == 1) pq.pop();
        resp = 0;
    }
}
