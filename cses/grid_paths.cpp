#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#include <bitset>
#define ll long long
#define INF 99999999
#define MAX 7
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
int resp, passou[10][10];

int e(int a, int b)
{
	return (a > 0 && b > 0 && a <= 7 && b <= 7 && !passou[a][b]);
}

void f(int a, int b, int tam)
{
	if (tam == 49) {
		resp += (a == 7 && b == 1);
		return;
	}

	if (a == 7 && b == 1) return;

	passou[a][b] = 1;
	if (e(a-1, b) && (s[tam-1] == 'U' || s[tam-1] == '?'))
	{
		if (!(e(a-1, b+1) && e(a-1, b-1) && !e(a-2, b)))
			f(a-1, b, tam+1);
	}
	if (e(a+1, b) && (s[tam-1] == 'D' || s[tam-1] == '?'))
	{
		if (!(e(a+1, b+1) && e(a+1, b-1) && !e(a+2, b)))
			f(a+1, b, tam+1);
	}
	if (e(a, b-1) && (s[tam-1] == 'L' || s[tam-1] == '?'))
	{
		if (!(e(a+1, b-1) && e(a-1, b-1) && !e(a, b-2)))
			f(a, b-1, tam+1);
	}
	if (e(a, b+1) && (s[tam-1] == 'R' || s[tam-1] == '?'))
	{
		if (!(e(a+1, b+1) && e(a-1, b+1) && !e(a, b+2)))
			f(a, b+1, tam+1);
	}
	passou[a][b] = 0;
}

int main()
{_
	cin >> s;
	f(1, 1, 1);
	cout << resp << endl;
}





















