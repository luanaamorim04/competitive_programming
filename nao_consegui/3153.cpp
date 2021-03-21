#include <iostream>
#define _ std::ios_base(0); cin.tie(0); cout.tie(0);
#include <map>

using namespace std;

map<string, int> mapa;
string s, cmd, pref;
int n, idx, ans;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd[0] == 'a') 
        {
            cin >> s;
            pref = "";
            for (int i = 0; i < s.size(); i++)
            {
                pref += s[i];
                ++mapa[pref];
            }
        }
        else
        {
            cin >> s;
            cout << mapa[s] << '\n';
        }
    } 
}