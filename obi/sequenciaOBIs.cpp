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
#define INF 1e9
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, l, r, arr[1<<17], bits[1<<17], resp, idx;
priority_queue<par, vector<par>, greater<par> > pq;

/*
    2, 3
    0 0 1 1 1 0 1 0 0 1
  i 1 2 3 4 5 6 7 8 9 10
  r 0 0 0 2 3 3 4 4 4 6
  l 0 0 0 0 0 0 3 3 3 4
*/

int achar_r(int ini, int k)
{
    int meio, fim = k;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (bits[k] - bits[meio] >= a) ini = meio + 1;
        else fim = meio - 1;
    }
    return ini - 1;
}

int achar_l(int ini, int k)
{
    int meio, fim = k;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (bits[k] - bits[meio] <= b) fim = meio - 1;
        else ini = meio + 1;
    }
    return fim + 1;
}

int main()
{_
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> bits[i];
        bits[i] += bits[i - 1];
    }
    bits[n + 1] = bits[n];

    resp = -(1e9);
    for (int i = 1; i <= n; i++)
    {   
        r = achar_r(1, i);
        l = achar_l(0, i);
        while (!pq.empty() && pq.top().second < l) pq.pop();
        for (int j = idx; j <= r; j++)
        {
            pq.push(par(arr[idx], idx));
            idx++;
        }
        if (bits[i] - bits[r] >= a) resp = max(resp, arr[i] - pq.top().first);
    }   

    cout << resp << endl;
}