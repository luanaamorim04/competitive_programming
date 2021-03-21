#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define tipo map<string, string>::iterator
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define line '\n'

using namespace std;

int cmp(int a, int b)
{
    if (a % 2 == 0 && b % 2 == 0) return a < b;
    else if (a % 2 != 0 && b % 2 != 0) return a > b;
    else if (a % 2 != 0 && b % 2 == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n, cmp);

    for (int i = 0; i < n; i++)
        cout << num[i] << endl;
}