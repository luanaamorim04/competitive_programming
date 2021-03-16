#include <iostream>
#include <vector>

#define INF -1000000000

using namespace std;

int n, temp;

void merge_sort(vector<int> &v)
{
    if (v.size() == 1) return;

    vector<int> v1, v2;

    for (int i = 0; i < v.size() / 2; i++)
        v1.push_back(v[i]);

    for (int i = v.size() / 2; i < v.size(); i++)
        v2.push_back(v[i]);

    merge_sort(v1);
    merge_sort(v2);

    v1.push_back(INF);
    v2.push_back(INF);

    int ini1 = 0, ini2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v1[ini1] > v2[ini2])
        {
            v[i] = v1[ini1];
            ini1++;
        }
        else
        {
            v[i] = v2[ini2];
            ini2++;
        }
        
    }
    return;

}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    merge_sort(a);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}