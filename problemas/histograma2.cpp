#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#define INF (long long) (1e9 + 9)
#define MAX 3000000
#define ll long long
#define MOD 1000000007
#define par pair<ll, ll>
#define pp pair<int, par>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<ll, int> mapa;
ll ESQ[MAX], DIR[MAX], esq[MAX], dir[MAX], arr[MAX], n, copia[MAX];
ll resp;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        copia[i] = arr[i];
    }

    sort(copia+1, copia+1+n);
    for (int i = 1; i <= n; i++)
        mapa[copia[i]] = i;

    for (int i = n; i >= 1; i--)
    {
        copia[i] = mapa[arr[i]]--;
        DIR[i] = dir[i] = i + 1;
        while (copia[DIR[i]] <= copia[i] && DIR[i] != n + 1) DIR[i] = DIR[DIR[i]];
        while (copia[dir[i]] >= copia[i] && dir[i] != n + 1) dir[i] = dir[dir[i]];
    }

    for (int i = 1; i <= n; i++)
    {
        esq[i] = ESQ[i] = i - 1;
        while (copia[esq[i]] >= copia[i] && esq[i] != 0) esq[i] = esq[esq[i]];
        while (copia[ESQ[i]] <= copia[i] && ESQ[i] != 0) ESQ[i] = ESQ[ESQ[i]];
        resp += arr[i]*(DIR[i] - i)*(i - ESQ[i]);
        resp -= arr[i]*(dir[i] - i)*(i - esq[i]);
    }

    cout << resp << endl;
}