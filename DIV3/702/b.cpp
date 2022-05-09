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

priority_queue<par> pq;
int t, n, x, c[3];

int main()
{_
    cin >> t;
    while (t--)
    {
        int resp = 0;
        cin >> n;
        c[0] = c[1] = c[2] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            ++c[x % 3];
        }

        pq.push(par(c[0], 0));
        pq.push(par(c[1], 1));
        pq.push(par(c[2], 2));

        while (c[pq.top().second] > n/3)
        {
            int idx = pq.top().second;
            c[idx]--, c[(idx + 1) % 3]++, resp++;
            pq.pop(), pq.pop(), pq.pop();
            pq.push(par(c[0], 0));
            pq.push(par(c[1], 1));
            pq.push(par(c[2], 2));
        }

        pq.pop(), pq.pop(), pq.pop();

        cout << resp << endl;
    }
}