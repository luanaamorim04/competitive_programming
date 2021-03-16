#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string s;
int counter;

int main()
{_
    
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (counter % 2 || s[i] == 32) cout << s[i];
        if (s[i] == 32) counter = 1;
        counter++;
    }

    cout << endl;
}