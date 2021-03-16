#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int mar[101][101];

int main()
{_
    int n, a1, a2, b1, b2, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        for (int i = a1; i < a2; i++)
        {
            for (int j = b1; j < b2; j++)
            {
                if (!mar[i][j])
                {
                    ans++;
                }
                mar[i][j]++;
            }
        }
    }

    cout << ans << endl;
}