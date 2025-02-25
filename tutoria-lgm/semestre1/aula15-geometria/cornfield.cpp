#include <iostream> 
#include <math.h>
#define ll long long

using namespace std;

struct vetor
{
    double x, y;

    vetor operator +(vetor q) const
    {
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const
    {
        return {x - q.x, y - q.y};
    }
    double operator ~() const 
    {
        return hypot(x, y);
    }
    double operator *(vetor q) const 
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(vetor q) const 
    {
        return (x*q.y - y*q.x);
    }
};

double m, n, k;

int32_t main()
{
	cin >> n >> k;
	vetor a = {0, k};
	vetor b = {k, 0};
	vetor c = {n, n-k};
	vetor d = {n-k, n};
	
	cin >> m;
	while (m--)
	{
		double xx, yy;
		cin >> xx >> yy;
		vetor g = {xx, yy};
	
		if (((g-b)^(a-b)) == 0 || ((g-c)^(b-c)) == 0 || ((g-d)^(c-d)) == 0 || ((g-d)^(a-d)) == 0) 
		{
			cout << "YES" << endl;
			continue;
		}
		int d1 = 0, d2 = 0;
		d1 = (((g-b)^(a-b)) > 0)^(((c-d)^(g-d)) > 0);
		d2 = (((g-b)^(c-b)) > 0)^(((a-d)^(g-d)) > 0);
		cout << (d1 && d2 ? "YES" : "NO") << endl;
		
	}
}

