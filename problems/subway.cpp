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

ll n, k, resp, psa[1<<20], tmp, pos, arr[1<<20], cp[1<<20];
map<int, int> mapa;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mapa[arr[i]] = i;
    }
    sort(arr+1, arr+1+n);
    for (int i = 1; i <= n; i++) 
        psa[i] = psa[i - 1] + arr[i];
    
    cin >> k;
    for (int i = 1; i <= k; i++) 
    {
        resp += (((i-1)*arr[i]) - psa[i-1]);
    }
    pos = k;
    tmp = resp;

    for (int i = k + 1; i <= n; i++)
    {   
        ll soma = psa[i-1] - psa[i-k];
        tmp += ((k-1)*arr[i] - soma);
        tmp -= (soma - ((k-1)*arr[i-k]));
        if (resp > tmp)
        {
            resp = tmp;
            pos = i;
        }
    }
    for (int i = pos-k+1; i <= pos; i++)
        cout << mapa[arr[i]] << ' '; 
    cout << endl;
}
