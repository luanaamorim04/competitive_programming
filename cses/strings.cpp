#include <iostream>
#include <set>

using namespace std;

int n;
string x;
set<string> str;
set<string>::iterator it;

void f(int mask, string s)
{
    if (s.size() == n) 
    {
        str.insert(s);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((mask) & (1 << i)) continue;
        f(mask + (1 << i), s + x[i]);
    }
}

int main()
{
    cin >> x;
    n = x.size();
    f(0, "");
    cout << str.size() << endl;
    for (it = str.begin(); it != str.end(); it++)
        cout << *it << endl;
}