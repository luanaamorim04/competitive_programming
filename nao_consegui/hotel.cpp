#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, atual, ans, k, x;
pair<int, int> hotel[10009];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        hotel[i].first = x;
        hotel[i].second = i;

        if (i < k) 
        {
            ans += hotel[i].first;
        }
    }

    sort(hotel, hotel+n);

    for (int i = 0; i < n; i++)
    {
    }

    cout << ans << endl;
}