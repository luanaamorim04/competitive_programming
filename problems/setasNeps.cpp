#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, i, uns[1000009], ans;

int main()
{_
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> uns[i];
        if (i && uns[i] == uns[i - 1] && i < n - 1)
        {
            ans++;
            uns[i] *= -1;
        }
    }

    cout << ans << "\n\n";
}