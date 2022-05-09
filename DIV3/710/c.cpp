#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s1, s2;
int t, tmp;

int main()
{_
    cin >> t;
    while (t--)
    {
        int resp = 0;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s2.size(); j++)
            {       
                tmp = 0;
                int x = i, y = j;
                while (x < s1.size() && y < s2.size() && s1[x++] == s2[y++]) tmp++;
                resp = max(resp, tmp);
            }
        }
        cout << s1.size() + s2.size() - 2*resp << endl;
    }
}