#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, r, l, c, h, idx;
double caixas[10000], esfera[100000];

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> c >> h;
        l*=l, c*=c, h*=h;
        caixas[i] = sqrt(l+c+h);
    }

    sort(caixas, caixas+n);

    for (int i = 0; i < m; i++)
        cin >> esfera[i];

    sort(esfera, esfera+m);

    for (int i = 0; i < m; i++)
        if (2*esfera[i] > caixas[idx] && idx <= n)
            idx += (2*esfera[i] > caixas[idx]);

    cout << idx << endl;
}