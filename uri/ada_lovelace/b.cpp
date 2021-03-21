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
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, k;
int pode, palavra;
char cobol[] = {'C', 'O', 'B', 'O', 'L', 'c', 'o', 'b', 'o', 'l'}, first, last;

int main()
{_
    while (cin >> k)
    {
        pode = 0;
        palavra = 0;
        s = "-";
        s += k;
        s += '-';
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i - 1] == '-') first = s[i];
            if (s[i + 1] == '-')
            {
                last = s[i];
                if ((first != cobol[palavra] && first != cobol[palavra + 5]) && (last != cobol[palavra] && last != cobol[palavra + 5])) pode = -1;
                palavra++;
            }
        }

        cout << (pode != -1 ? "GRACE HOPPER" : "BUG") << endl;
    }
}