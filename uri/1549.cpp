#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const double PI = 2*acos(0.0);

int c;
double b, B, H, n, L, k;

double raio(double H, double B, double h, double b)
{
	return (((h*(B-b)) + (H*b))/H);
}

double volume(double R, double h, double r)
{
	return (PI*h/3)*((R*R) + (R*r) + (r*r));
}

double bb()
{
	int cnt = 100;
	double ini = 0, meio, fim = H;
	while (cnt--)
	{	
		meio = ((ini+fim)/2);
		if (volume(raio(H, B, meio, b), meio, b) >= k) fim = meio;
		else ini = meio;
	}

	return meio;
}

int main()
{_
	cin >> c;
	while (c--)
	{
		cin >> n >> L;
		k = L/n;
		cin >> b >> B >> H;
		cout << fixed << setprecision(2) << bb() << endl;
	}
}















