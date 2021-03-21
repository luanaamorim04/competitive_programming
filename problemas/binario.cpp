#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x, psa[30][4], maxn, ans;
vector<int> out;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x; // input
        while (x > 0) // transform x in binary and then count the digits
        {
            psa[i][2]++;
            psa[i][x%2]++;
            x /= 2;
        }
        if (psa[i][2] > maxn) maxn = psa[i][2]; // get max number
    }
    for (int i = 1; i <= n; i++)
    {
        psa[i][0] += psa[i - 1][0] + maxn - psa[i][2]; // add 0's to the numbers
        psa[i][1] += psa[i - 1][1]; // create the prefix sum array
        for (int j = 0; j < i; j++) // loop over all other indexes
            if (psa[i][0] - psa[j][0] == psa[i][1] - psa[j][1]) ans++; // check if the digist are equal
    }

    while (ans > 0) // transform anwser in binary
    {
        out.push_back(ans%2);
        ans /= 2;
    }

    maxn -= out.size(); // re-use variable

    for (int i = 0; i < maxn; i++) // output the zeros as required
        cout << 0;

    maxn = out.size() - 1; // re-use variable

    for (int i = maxn; i >= 0; i--) // output the anwser
        cout << out[i];

    cout << endl; // skip a line
}