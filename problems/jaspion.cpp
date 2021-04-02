#include <iostream>
#include <map>
#include <sstream>

using namespace std;

map<string, string> trad;
string jap, port, palavra;
int n, m, t;

int main()
{
    cin >> t;
    while (t--)
    {
        trad.clear();
        if (m) cout << endl;
        cin >> m >> n;
        getline(cin, jap);
        while (m--)
        {
            getline(cin, jap);
            getline(cin, port);
            trad[jap] = port;
        }

        while (n--)
        {
            getline(cin, jap);
            stringstream ss(jap);
            while (ss >> palavra)
            {
                if (trad[palavra] != "") cout << trad[palavra] << ' ';
                else cout << palavra << ' ';
            }
            cout << endl;
        }
    }
}