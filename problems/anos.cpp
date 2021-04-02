#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int len, leap, hulu, bulu, base1, base2, base3, linha, ok;

int main()
{_
    string ano;
    while (cin >> ano)
    {
        if (linha) cout << '\n';
        linha = 1;
        len = ano.size() - 1, leap = 0, hulu = 0, bulu = 0, base1 = 1, base2 = 1, base3 = 1, ok = 0;
        for (int i = len; i > -1; i--)
        {
            leap = (leap + (ano[i] - '0') * base1) % 400;
            hulu = (hulu + (ano[i] - '0') * base2) % 15;
            bulu = (bulu + (ano[i] - '0') * base3) % 55;
            base1 = (base1 % 400 * 10) % 400;
            base2 = (base2 % 15 * 10) % 15;
            base3 = (base3 % 55 * 10) % 55;
        }

        if (!leap|| (leap % 100 && !(leap % 4)))
        {
            cout << "This is leap year.\n";
            ok = 1;
        }
        if (!hulu)
        {
            cout << "This is huluculu festival year.\n";
            ok = 1;
        }
        if (!bulu && (!leap|| (leap % 100 && !(leap % 4))))
            cout << "This is bulukulu festival year.\n";

        if (!ok)
            cout << "This is an ordinary year.\n";

    }
}