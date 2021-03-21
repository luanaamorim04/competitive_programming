#include <iostream>

using namespace std;

string s;
int freq[100];

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        freq[s[i]]++;

    int imp, k = 0;
    for (int i = 'A'; i <= 'Z'; i++)
        if (freq[i] % 2) 
        {
            k++;
            imp = i;
        }

    if (s.size() % 2 == 0)
    {
        if (k) 
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (!freq[i]) continue;
            int x = freq[i] / 2;
            while (x--)
                cout << i;

            freq[i] /= 2;
        }

        for (char i = 'Z'; i >= 'A'; i--)
        {
            if (!freq[i]) continue;
            while (freq[i]--)
                cout << i;
        }
    }
    else
    {
        if (k != 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (!freq[i] || i == imp) continue;
            int x = freq[i] / 2;
            while (x--)
                cout << (char) i;
            freq[i] /=2;
        }

        for (int i = 0; i < freq[imp]; i++)
            cout << (char) imp;

        for (int i = 'Z'; i >= 'A'; i--)
        {
            if (!freq[i] || i == imp) continue;
            while (freq[i]--)
                cout << (char) i;
        }
    }
    
    cout << endl;
}