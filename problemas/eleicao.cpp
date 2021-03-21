#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define tipo map<int, int>::iterator
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define line '\n'

using namespace std;

int main()
{
    int n, maior = 0, res;
    cin >> n;
    map<int, int> f;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        f[tmp]++;
    }
    for (tipo it = f.begin(); it != f.end(); it++)
        if (it->second > maior)
        {
            maior = it->second;
            res = it->first;
        }
    cout << res << endl;
}