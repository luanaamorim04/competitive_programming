#include <iostream>
#include <map>

using namespace std;

map<int, int> res;

int main()
{
    int j, r, x, max, ans;
    cin >> j >> r;
    for (int i = 0; i < j * r; i++)
    {
        cin >> x;
        res[i % j] += x;
    }

    for (map<int, int>::iterator it = res.begin(); it != res.end(); it++)
    {
        if (it->second > max)
        {
            ans = it->first;
            max = it->second;
        }
        else if (it->second == max && it->first > ans)
            ans = it->first;
    }

    cout << ans + 1 << endl;
}