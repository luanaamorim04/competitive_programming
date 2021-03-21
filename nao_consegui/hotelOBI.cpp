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

int N, K, a[100009], dp[100009], p[10009];
map<par, int> mapa;

int f(int dia, int pts)
{
    if (pts < 0) return INF;
    if (dia == N) return 0;
    if (mapa.count(make_pair(dia, pts))) return mapa[make_pair(dia, pts)];
    return mapa[make_pair(dia, pts)] = min(a[dia] + f(dia + 1, pts + 1), f(dia + 1, pts - K));
}

int main()
{_
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << f(0, 0) << endl;
}