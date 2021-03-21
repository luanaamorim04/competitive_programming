#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define tipo map<string, string>::iterator
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define line '\n'

using namespace std;

int n;
string dna;
set<string> res;


int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0) break;

        getline(cin, dna);
        while (n--)
        {
            getline(cin, dna);
            sort(dna.begin(), dna.end());
            res.insert(dna);
        }

        cout << res.size() << endl;
        res.clear();
    }

}