#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, atual, ans;
pair<int, int> bolsas[10009];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> bolsas[i].second >> bolsas[i].first;

    sort(bolsas, bolsas+n);

    for (int i = 0; i < n; i++)
    {
        atual += bolsas[i].second;
        ans = max(ans, max(0LL, atual - bolsas[i].first));
    }

    cout << ans << endl;
}