#include <iostream> 
#include <iomanip>
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

double m, n, h;

double f(double k)
{
	return k*k/(2*h);	
}

int32_t main()
{
	cin >> n >> h;
	double area = (h/2)/n, last = 0;

	for (int i = 1; i < n; i++)
	{
		int cnt = 100;
	   	double ini = 0, fim = h;
		while (cnt--)
		{
			double mid = (ini+fim)/2;
			if (f(mid) > i*area) fim = mid;
			else ini = mid;
		}

		cout << fixed << setprecision(10) << ini << ' ';
	}
	cout << endl;
}


