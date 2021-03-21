#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int n, c, id, num;
map<int, int> infect;
vector<int> res;

int main()
{_
    cin >> n >> c;
    while (c--)
    {
        cin >> id >> num;
        while (num--)
        {
            cin >> id;
            infect[id]++;
        }
    }

    for (map<int, int>::iterator it = infect.begin(); it != infect.end(); it++)
    {
        if (it -> second == 0)
            res.push_back(it -> first);
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
}