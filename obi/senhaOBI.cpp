#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int pos[6][10], resp[10], n, t;
pair<int, int> num[10], letra[100];
char c;

int main()
{_  
    while (cin >> n && n)
    {
        while (n--)
        {
            for (int i = 'A'; i <= 'E'; i++)
                cin >> letra[i].first >> letra[i].second;

            for (int i = 0; i < 6; i++)
            {
                cin >> c;
                pos[i][letra[c].first]++;
                pos[i][letra[c].second]++;
            }
        }

        cout << "Teste " << ++t << endl;

        for (int i = 0; i < 6; i++)
        {
            int resp = 0, d;
            for (int j = 0; j <= 9; j++)
            {
                if (resp < pos[i][j]) resp = pos[i][j], d = j;
                pos[i][j] = 0;
            }
            cout << d << ' ';
        }
        cout << endl << endl;
    }
}