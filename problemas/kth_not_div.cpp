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

ll x, n, k, bloco, sobra, resp;

int main()
{_
    cin >> x;
    while (x--)
    {
        cin >> n >> k;
        bloco = (k+n-2)/(n-1);
        sobra = bloco*(n-1) - k;
        resp = n - 1 - sobra;
        cout << ((bloco-1)*n) + resp << endl;
    }
}
