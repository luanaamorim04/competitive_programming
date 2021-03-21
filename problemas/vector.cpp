#include <iostream>
#include <map>
#define mp make_pair

using namespace std;

map< pair<int, int>, int > indexx;
map<int, int> freq;

int main()
{
    int n, m, a, b, tmp;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            freq[tmp]++;
            indexx[mp(freq[tmp], tmp)] = i + 1;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            cout << indexx[mp(a, b)] << endl;
        }
        indexx.clear();
        freq.clear();
    }
}