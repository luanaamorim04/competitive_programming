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

int arr[1<<20], pos[1<<20], n, m, a, b, resp, menor_frente[1<<20], maior_atras[1<<20];

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (pos[arr[i] + 1] < pos[arr[i]]) 
        {
            resp++;
            menor_frente[arr[i] + 1] = maior_atras[arr[i]] = 1;
        }
    }

    while (m--)
    {
        cin >> a >> b;
        if (pos[arr[a] + 1] <= b)
        {
            resp += maior_atras[arr[a] + 1] - 1;
        }
        pos[arr[a]] = b;
        pos[arr[b]] = a;
        swap(arr[a], arr[b]);
        cout << resp << endl;
    }
}
