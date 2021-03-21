#include <iostream>
#include <vector>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, lobo[51], a, b, ans, pos1[100], pos2[100], des[100];

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos1[i] >> pos2[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pos1[j] == i || pos2[j] == i)
            {
                des[j] = i;
            }
        }
    }

    cout << ans << endl;

}