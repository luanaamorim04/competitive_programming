#include <iostream>
#include <map>

using namespace std;

map<int, int> freq;

int main()
{
    int n, x, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second % 2 == 0) res += it->second;
        else res += it->second + 1;
    }

    cout << res << endl;
}