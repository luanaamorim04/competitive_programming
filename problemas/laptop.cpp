#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> v1[100000];
pair<int, int> v2[100000];

int cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i].first >> v1[i].second;
        v2[i] = v1[i];
    }
    sort(v1, v1 + n, cmp1);
    //sort(v2, v2 + n, cmp2);
    for (int i = 0; i < n - 1; i++)
    {
        if (v1[i].first < v1[i + 1].first && v1[i].second > v1[i + 1].second)
        {
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
}