#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{_
    int n, num, a, ans;
    while (cin >> n)
    {
        num = 0;
        a = 1;
        ans = 0;
        while (true)
        {
            ans++;
            num = (num + a) % n;
            a = (a * 10) % n;
            if (num == 0)
            {
                cout << ans << endl;
                break;
            }
        }
    }
}