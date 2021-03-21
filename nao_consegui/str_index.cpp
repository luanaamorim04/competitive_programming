#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<string> v;
string k;

int f(int idx, string s)
{
    v.push_back(s);
    if (idx == 5) return;
    for (char i = 'a'; i <= 'z'; i++)
    {
        f(idx + 1, s + i);
    }
}

int main()
{_
    
}