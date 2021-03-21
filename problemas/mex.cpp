#include <iostream>
#include <map>
#include <set>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

set<pair<int, int> > res;
map<int, int> freq;

int main()
{_
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        res.insert(make_pair(0, i));
    }
    while (n--)
    {
        cin >> x;
        res.erase(make_pair(freq[x % m], x % m));
        freq[x % m]++;
        res.insert(make_pair(freq[x % m], x % m));
        cout << (*res.begin()).first * m + (*res.begin()).second << endl;
    }
}