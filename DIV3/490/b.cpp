#include <iostream>

using namespace std;

string s;
int divs[101], sz;

void reverse(int k)
{
    for (int i = k; i > k/2; i--)
    {
        swap(s[i], s[k - i]);
    }
}

int main()
{
    cin >> sz >> s;
    for (int i = 1; i <= sz; i++)
        if (sz % i == 0) reverse(i - 1);
    
    cout << s << endl;
}