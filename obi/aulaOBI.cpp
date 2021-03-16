#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n], count = 1;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);

    for (int i = 1; i < n; i++)
        if (p[i] != p[i - 1])
            count++;

    cout << count << endl;
}