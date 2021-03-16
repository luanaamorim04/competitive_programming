#include <iostream>
#include <algorithm>

using namespace std;

int n, q[100001], l[100001], ans;

int main()
{
    cin >> n;   
    for (int i = 0; i < n; i++)
        cin >> q[i];

    for (int i = 0; i < n; i++)
        cin >> l[i];

    sort(q, q+n);
    sort(l, l+n);

    int mais_fraco = 0, mais_forte = n - 1;

    for (int i = 0; i <= mais_forte; i++)
    {
        if (l[mais_fraco] > q[i]) ++ans;
        else --mais_forte, --i;
        ++mais_fraco;
    }

    cout << ans << '\n';
}   