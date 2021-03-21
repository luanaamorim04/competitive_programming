#include <iostream>

using namespace std;

int n, d, t, menor[10001], maior[10001], x, k;
string names[10001], resp;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> d;
        for (int i = 0; i < d; i++)
        {
            cin >> names[i] >> menor[i] >> maior[i];
        }

        cin >> n;
        while (n--)
        {
            k = 0;
            cin >> x;
            for (int i = 0; i < d; i++)
            {
                if (x >= menor[i] && x <= maior[i])
                {
                    ++k;
                    resp = names[i];
                }
            }

            if (k != 1) cout << "UNDETERMINED" << endl;
            else if (k == 1) cout << resp << endl;
        }
        cout << endl;
    }
}