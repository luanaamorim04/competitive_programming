#include <iostream>
#include <cmath>

using namespace std;

int n, s, d, atual, ans;

int main()
{
    cin >> n >> s >> d;

    while (atual < n)
    {
        atual += s;
        ans++;
        if (atual < n) atual -= d;
    }

    cout << ans << endl;
}